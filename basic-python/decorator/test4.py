#!/usr/bin/python

def wap(name):
	    def decorator1(func):
		def dec(*args):
			print name
			print 'pre action'
			result = func(*args)
			print 'post action'
			return result
		return dec
	    return decorator1

@wap('f1')
def test_f1(name):
	print name
        return None

@wap('f2')
def test_f2(name):	## likes test_f2 = wap(‘f2’)(test_f2)
	print name
	return None

test_f1('name1') ## out: f1/pre action/name1/post action
test_f2('name2') ## out: f2/pre action/name2/post action

# decorator with parameter, could do different actions in decorator

