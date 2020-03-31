import sys
import random


m = random.randint(1, 500000)
n = random.randint(1, m)
print(n, m)

for i in range(n):
    val = random.randint(1, 2000000)
    print(val, end=' ')
print()
for i in range(m):
    val = random.randint(1, 2000000)
    print(val, end=' ')


