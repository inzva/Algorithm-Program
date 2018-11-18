import sys
import random


t = 10

print(t)

while(t):
    n = 10000 #random.randint(3, 10000)
    print(n)
    print(1,2)
    print(1,3)
    
    ar = [i+4 for i in range(n-3)]
    random.shuffle(ar)

    goAbleLeft = [2]
    leftSize = (n-2)//2
    leftAr = ar[0:leftSize]
    for i in range(leftSize):
        print(goAbleLeft[random.randint(0,len(goAbleLeft)-1)], leftAr[i])
        goAbleLeft.append(leftAr[i])
    
    goAbleRight = [3]
    rightArr = ar[leftSize:len(ar)]
    for i in range(n-leftSize - 3):
        print(goAbleRight[random.randint(0,len(goAbleRight)-1)], rightArr[i])
        goAbleRight.append(rightArr[i])

    t -= 1
