#!/usr/bin/python3

class myDecorator(object):
	def __init__(self, f):
		print ("inside myDecorator.__init__()")
		self.f = f

	def __call__(self):
		print ("inside myDecorator.__call__()")
		self.f()


@myDecorator
def aFunction():
	print ("inside aFunction()")

print ("Finished decorating aFunction()")	

aFunction()
	

"""
output likes:

inside myDecorator.__init__()
Finished decorating aFunction()
inside myDecorator.__call__()
inside aFunction()

Very useful case:
likes:
@retries(3) 

https://wiki.python.org/moin/PythonDecoratorLibrary - central repository of decorator

