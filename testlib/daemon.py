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
import subprocess, os, signal


__all__ = ['Daemon']

def kill_child_processes(parent_pid, sig=signal.SIGTERM):
    ps_command = subprocess.Popen("ps -o pid --ppid %d --noheaders" % parent_pid, shell=True, stdout=subprocess.PIPE)
    ps_output = ps_command.stdout.read()
    retcode = ps_command.wait()
    #assert retcode == 0, "ps command returned %d" % retcode
    if retcode != 0:
        for pid_str in ps_output.split("\n")[:-1]:
            os.kill(int(pid_str), sig)


class Daemon(object):

    def __init__(self, pidfile, stdin = '/dev/null', stdout = '/dev/null', stderr = '/dev/null'):
        self.stdin = stdin
        self.stdout = stdout
        self.stderr = stderr
        self.pidfile = pidfile

    def daemonize(self):
        #第一次fork，生成子进程，脱离父进程
        try:
            pid=os.fork()
            if pid > 0:
                sys.exit(0)
        except OSError,e:
            sys.stderr.write("fork fist faild:%d (%s)\n" % (e.errno,e.strerror))
            sys.exit(1)

        #修改工作目录
        os.chdir('/')
        #设置新的会话连接
        os.setsid()
        #重新设置文件创建权限
        os.umask(0)

        #第二次fork，禁止进程打开终端
        try:
            pid=os.fork()
            if pid > 0:
                sys.exit(0)
        except OSError,e:
            sys.stderr.write("fork second faild:%d (%s)\n" % (e.errno,e.strerror))
            sys.exit(1)

        sys.stdout.flush()
        sys.stderr.flush()

        #重定向标准输入、输出
        si=file(self.stdin,'r')
        so=file(self.stdout,'a+')
        se=file(self.stderr,'a+',0)
        os.dup2(si.fileno(),sys.stdin.fileno())
        os.dup2(so.fileno(),sys.stdout.fileno())
        os.dup2(se.fileno(),sys.stderr.fileno())

        #注册退出函数
        atexit.register(self.delpid)
        pid=str(os.getpid())
        file(self.pidfile,'w+').write("%s\n" % pid)

    def delpid(self):
        os.remove(self.pidfile)

    def start(self):
        try:
            pf=open(self.pidfile,'r')
            pid=int(pf.read().strip())
            pf.close()
        except IOError:
            pid=None

        if pid:
            ms="pidfile %s already exist,daemon already running\n"
            sys.stderr.write(ms % self.pidfile)
            sys.exit(1)

        self.daemonize()
        self.run()

    def stop(self):
        try:
            pf=open(self.pidfile,'r')
            pid=int(pf.read().strip())
            pf.close()
        except IOError:
            pid=None

        if not pid:
            ms="pidfile %s does not exit,daemon not running\n"
            sys.stderr.write(ms % self.pidfile)
            return

        try:
            kill_child_processes(pid)
            while 1:
                os.kill(pid,SIGTERM)
                time.sleep(0.1)
                os.remove(self.pidfile)
        except OSError,err:
            err=str(err)
            if err.find('No sush process') > 0:
                if os.path.exists(self.pidfile):
                    os.remove(self.pidfile)
                else:
                    print str(err)
                    sys.exit(1)

    def restart(self):
        self.stop()
        self.start()

    #该方法用于在子类中重新定义，用来运行你的程序
    def run(self):
         """ run your fun"""
         pass

