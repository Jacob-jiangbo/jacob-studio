#!/usr/bin/python

def f1(arg):
	    print ("f1")
	    rl = arg()
	    print (rl)
	    return rl + "f1"

def f2(arg = ""):
    print ("f3")
    return arg + "f2r"


print ("start")
print f1(f2)

"""
Output likes:
f1
f3
f2r
start
f2rf1
"""

