import sys
from random import randint


n, p = randint(1, 100), 100000000 #randint(1, 100000000)
print(n,p)

print(' '. join([ str(randint(1,15)) for i in range(n)]))

a, b = 3000, 3000

print(a, b)

for i in range(a):
        print(''.join([str(randint(0,1)) for i in range(b)]))



