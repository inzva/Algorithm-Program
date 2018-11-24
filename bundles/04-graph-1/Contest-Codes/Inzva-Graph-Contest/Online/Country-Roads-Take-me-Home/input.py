from random import randint, shuffle

n = randint(2, 2000)
g = randint(1, (n*n - 1)//10)
h = randint(1, (n*n - 1 - g)//10)
t = 100000 #randint(1, 100000)

print(n, g, h, t)


tomPos = []
for i in range(n):
    for j in range(n):
        if(i != 0 and j != 0):
            tomPos.append((i,j))

shuffle(tomPos)
tomatoes = [[0 for i in range(n)] for i in range(n)]
for i in range(g):
    print(tomPos[i][0], tomPos[i][1])
    tomatoes[ tomPos[i][0] ][ tomPos[i][1] ] = 1;



allPositions = []
for i in range(n):
    for j in range(n):
        if((i != 0 or j != 0) and tomatoes[i][j] == 0):
            allPositions.append((i,j))

shuffle(allPositions)
for i in range(h):
    print(allPositions[i][0], allPositions[i][1])


for i in range(t):
    print(randint(1, n-1))
