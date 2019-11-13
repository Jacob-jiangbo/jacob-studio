#!/usr/bin/python3

def f1(arg):
	    print ("f1")
	    rl = arg()
	    print (rl)
	    return rl + "f1"

@f1
def f2(arg = ""):
    print ("f3")
    return arg + "f2r"


print ("start")
print f2
# print f2("3")  <--- Won't have error

"""
output is :
f1
f3
f2r
start
f2rf1

so that means, during import , decorator already begin to run liks f1(f2)
and f2 is replaced as one string of "f2rf2"

and f2 can't be used liks f2(3) anymore. 


"""

