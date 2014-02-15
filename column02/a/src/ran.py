import random

maxLength = 1000000
count = 0
while count < maxLength:
    i = random.randint(0, 0xFFFFFFFF)
    print i
    count = count + 1


