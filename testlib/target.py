#! /usr/bin/env python
#coding:utf-8

import pexpect
import time
import sys
import re
import datetime
import logging
import os
import atexit
from optparse import OptionParser
from signal import SIGTERM

__all__ = ['Target']


class Target(object):
    def __init__(self, _host, _username, _password,  _parameter=None, _str_prompt = '\# '):

        opts=OptionParser()
        opts.add_option("--loglevel",   "-l",   help="loglevel")
        options, arguments = opts.parse_args()

        # Parse and set arguments.
        if options.loglevel:
            self.loglevel =  options.loglevel
        else:
            self.loglevel = "INFO"

        self.set_prompt(_str_prompt)
        #self._logfile = os.path.join(os.getcwd() + 'register_agent.log')
        self._logfile = '/tmp/register_agent.log'
        self.set_logfile(_host)

        self.log_mode = 1

        self.tg_info = {'host': _host, 'username': _username, 'password': _password,'parameter': _parameter
                        }

        self.ssh_handle=pexpect.spawn('ssh '+ self.tg_info['parameter'] + self.tg_info['username'] + '@' + self.tg_info['host'])
        for loop in range(1,8):
            exp_index = self.ssh_handle.expect ([
            self.str_prompt,                         # 0  expect prompt
            pexpect.TIMEOUT,                         # 1
            pexpect.EOF,                             # 2
            'yes/no',                                # 3  If added new line here, please notice
            'password: ',                              # 4  the index is used in the if elif lines.
            'Password: ',                            # 5
            'Permission denied, please try again.',  # 6
            'Connection closed by UNKNOWN'           # 7
            ], timeout=10)

            if 0 == exp_index:
                if 1 == self.log_mode:
                    self.ssh_handle.logfile = sys.stdout
                elif 2 == self.log_mode:
                    self.ssh_handle.logfile_read = sys.stdout
                elif 3 == self.log_mode:
                    fout = file(self._logfile,'w')
                    self.ssh_handle.logfile = fout
                elif 4 == self.log_mode:
                    fout = file(self._logfile,'w')
                    self.ssh_handle.logfile_read = fout
                self.clean_buff()
                self.logger.info("#"+"-" * 69)
                self.logger.info('Ssh connect sucessfully.')
                self.logger.info("#"+"-" * 69)
                break
            elif 3 == exp_index:
                self.ssh_handle.sendline('yes')
            elif 4 == exp_index or 5 == exp_index:
                self.ssh_handle.sendline(self.tg_info['password'])
            else:
                self.logger.error('Ssh connect failed.')
                self.ssh_handle.close(force=True)

    def disconnect(self):
        logging.shutdown()
        self.ssh_handle.close(force=True)

    def set_prompt(self, str_prompt):
        self.str_prompt = str_prompt

    def set_logfile(self, _user_case):
        self.logger = logging.getLogger(_user_case)
        formatter = logging.Formatter('%(name)-%(levelname)-8s %(message)s', '%a, %d %b %Y %H:%M:%S',)
        file_handler = logging.FileHandler(self._logfile )
        file_handler.setFormatter(formatter)
        self.logger.addHandler(file_handler)
        self.logger.setLevel(self.loglevel)
        self.logger.info("#"+"-" * 69)
        self.logger.info('Session log started.')
        self.logger.info("#"+"-" * 69)

    def clean_buff(self):
        for loop in range(1,3):
            exp_index = self.ssh_handle.expect([self.str_prompt, pexpect.TIMEOUT, pexpect.EOF], 0.1)
        if 2 == exp_index:
            self.logger.error('expect EOF. what happened?')
            self.ssh_handle.close(force=True)

    def send_command(self, cmd, timeout=6, ignore_fail = 0, str_prompt = '\# '):
        self.set_prompt(str_prompt)
        self.print_cmd_output('[cmd]# '+cmd)
        #we only send the command once, but spend more time for the expect return
        buff = ''
        self.ssh_handle.sendline(cmd)
        wait_times = 10
        ret = 1
        for count in range(1, wait_times+1):
            try:
                exp_index = self.ssh_handle.expect(self.str_prompt, timeout)
                if exp_index == 0:
                    ret = 0
                    buff += self.ssh_handle.before
                    break
            except pexpect.EOF:
                self.logger.error('command: %s failed. [EOF]' %(cmd))
                break
            except pexpect.TIMEOUT:
                if count != wait_times:
                    self.logger.warning('command: %s failed, wait: %s. [TIMEOUT]' %(cmd, count))
                    time.sleep(3)
                    continue
        if ret == 1:
            self.logger.error('Send %s failed, resend times %d[timeout=%d]' %(cmd, resend, timeout))
            if ignore_fail == 0:
                self.ssh_handle.close(force=True)
                sys.exit()
            else:
                return False
        if not buff:
            self.logger.warning('command: %s [NO BUFF]' %(cmd))
            return False
        self.logger.debug('Send %s command ok' %(cmd))
        self.print_cmd_output(buff)
        return buff

    def send_last_command(self, cmd, timeout=-1, ignore_fail = 0, str_prompt = "Vport Statistics"):
        self.print_cmd_output('[cmd]# '+cmd)
        buff = ''
        self.ssh_handle.sendline(cmd)
        ret = 1
        while True:
            try:
                exp_index = self.ssh_handle.expect(str_prompt, timeout)
                if exp_index == 0:
                    ret = 0
                    buff += self.ssh_handle.before
                    #break
            except pexpect.EOF:
                self.logger.error('command: %s failed. [EOF]' %(cmd))
                break
            except pexpect.TIMEOUT:
                if count != wait_times:
                    self.logger.waring('command: %s failed, wait: %s. [TIMEOUT]' %(cmd, count))
                    time.sleep(3)
                    continue
        if ret == 1:
            self.logger.error('Send %s failed, resend times %d[timeout=%d]' %(cmd, resend, timeout))
            if ignore_fail == 0:
                self.ssh_handle.close(force=True)
                sys.exit()
            else:
                return False
        if not buff:
            self.logger.warning('command: %s [NO BUFF]' %(cmd)) #still return, handled by users
            return False
        self.logger.debug('Send %s command ok' %(cmd))
        self.print_cmd_output(buff)
        return buff

    def print_cmd_output(self, _str):
        self.logger.info(_str)


