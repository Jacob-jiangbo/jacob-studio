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
from testlib.daemon import Daemon
from testlib.target import Target

Host1 = "ala-lpd-test1.wrs.com"
User1 = "jwang6"
Passwd1 = "BAme26bo"
Parameter1 = " -D localhost:6666 "


class RegAgentDaemon(Daemon):
    def run(self):
        fp=open('/tmp/result','a+')
        fp.write('Enter in RegAgentDaemon\n')
        tg = Target(_host = Host1, _username = User1, _password = Passwd1, _parameter = Parameter1, _str_prompt = '\$')
        while True:
            time.sleep(2)

if __name__ == '__main__':
    daemon = RegAgentDaemon('/tmp/reg_agent_pidfile', stdout='/tmp/result')
    if len(sys.argv) == 2:
        if 'start' == sys.argv[1]:
            print "daemon_start"
            daemon.start()
        elif 'stop' == sys.argv[1]:
            daemon.stop()
        elif 'restart' == sys.argv[1]:
            daemon.restart()
        else:
            print 'unkonow command'
            sys.exit(2)
        sys.exit(0)
    else:
        print "usage:%s start/stop/restart" % sys.argv[0]
        sys.exit(2)




