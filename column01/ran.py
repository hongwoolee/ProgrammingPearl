import random

maxLength = 10000000
L = range(0, maxLength)

random.shuffle(L)
for i in L:
    print L[i]

