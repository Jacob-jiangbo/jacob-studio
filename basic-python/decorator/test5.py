#!/usr/bin/python

def decorator1(func):
    def dec(*args):
        print 'd1 pre'
	result = func(*args)
        print 'd1 post'
	return result
    return dec

def decorator2(func):
    def dec(*args):
        print 'd2 pre'
	result = func(*args)
        print 'd2 post'
	return result
    return dec

@decorator1
@decorator2
def test(name):
    print name

test('test')

"""
output:
d1 pre
d2 pre
test
d2 post
d1 post

Note:
test = decorator1(decorator2(test))

would run decorator1 firstly , then run decorator2 as parameter

