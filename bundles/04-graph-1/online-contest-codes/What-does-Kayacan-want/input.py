import sys
import random


n = 5000000 # random.randint(2, 50000)
#availableEdges = []
#for i in range(n):
#    for j in range(n-i):
#        if(i+1 != n-j):
#            availableEdges.append((i+1, n-j))


m = 900000 # random.randint(2, len(availableEdges))

print(n, m)

visited = [[0]*n]*n

#random.shuffle(availableEdges)
for i in range(m):
    a, b = random.randint(0, n), random.randint(0, n)
    while(visited[a][b] == 1):
        a, b = random.randint(0, n), random.randint(0, n)
    
    visited[a][b] = 1
    print(a, b)
