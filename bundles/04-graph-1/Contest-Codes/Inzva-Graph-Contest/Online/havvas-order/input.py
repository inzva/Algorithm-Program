import sys
import random


t = random.randint(1, 10)

print(t)

while(t):
    n = random.randint(2, 100000)

    ar = [i+1 for i in range(n)]
    random.shuffle(ar)

    root = ar[0]
    print(n, root)
    rootGo = ar[1]

    goAble = [root, rootGo]
    for i in range(n-1):
        if(i == 0):
            print(root, rootGo)
        else:
            print(goAble[random.randint(0,10000000)%len(goAble)], ar[i+1])
            goAble.append(ar[i+1])

    t -= 1
