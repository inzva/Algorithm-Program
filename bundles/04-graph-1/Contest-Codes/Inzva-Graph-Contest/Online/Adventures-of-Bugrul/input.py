#from random import randint
#
## n = 500000
#n = 10
## root = randint(0, 500000)
#root = 0
#print(str(n) + " " + str(root))
#
#previousList = [root]
#
## canBeNodeList = [i for i in range(500001)]
#canBeNodeList = [i for i in range(20)]
#canBeNodeList.pop(root)
#
#for i in range(n-1):
#    rootOfCurrentNum = previousList[randint(0, len(previousList)-1)]
#
#    lenX = randint(0, len(canBeNodeList)-1)
#    currentNode = canBeNodeList[lenX]
#    canBeNodeList.pop(lenX)
#
#    previousList.append(currentNode)
#    print(str(rootOfCurrentNum) + " " + str(currentNode))

import sys
import random

n = 500000
m = 1000000000
print(n,m)

for i in range(n-1):
    print(i+1, i+2)

#n = random.randint(1, 500000)
#m = random.randint(1, 1000000000)
#print(n, m)
#
#ar = [i+1 for i in range(n)]
#random.shuffle(ar)
#
#root = ar[0]
#rootGo = ar[1]
#
#goAble = [root, rootGo]
#for i in range(n-1):
#    if(i == 0):
#        print(root, rootGo)
#    else:
#        print(goAble[random.randint(0,10000000)%len(goAble)], ar[i+1])
#        goAble.append(ar[i+1])


