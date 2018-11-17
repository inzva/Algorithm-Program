import sys
import random


t = 10

print(t)

while(t):
    n = 100
    availableEdges = []
    for i in range(n):
        for j in range(n-i):
            if(i+1 != n-j):
                availableEdges.append((i+1, n-j))

    m = 500 #random.randint(1, 500)

    a, b = random.randint(1, n), random.randint(1, n)
    while(a == b):
        a, b = random.randint(1, n), random.randint(1, n)

    print(n, m, a, b)

    random.shuffle(availableEdges)
    for i in range(m):
        print(availableEdges[i][0], availableEdges[i][1])

    t -= 1
