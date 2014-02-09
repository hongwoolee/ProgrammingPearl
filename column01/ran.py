import random

maxLength = 10000000
L = range(0, maxLength)

count = 0
while count < maxLength:
    i = random.randint(0, maxLength-count-1)
    if i < 0:
        break
    print L[i]
    del L[i]
    count = count + 1



