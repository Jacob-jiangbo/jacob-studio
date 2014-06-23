# !/usr/bin/python

import random

# create random float from 0<=n<1.0
print random.random()

# create random float from a<=n<=b
print random.uniform(10, 20)

# create random int from a<=n<=b
print random.randint(10,20)


# create random int from a<=n<=b stepped by c
print random.randrange(10, 100, 2)

# create random var from a
print random.choice(["JGood", "is", "a", "handsome", "boy"])

# create random var from sample
list = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
slice = random.sample(list, 5)
print slice