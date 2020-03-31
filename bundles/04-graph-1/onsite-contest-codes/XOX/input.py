from random import randint


l = 'X.O'

for i in range(3):
    print(l[randint(0,2)] + l[randint(0,2)] + l[randint(0,2)])
