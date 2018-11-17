from random import randint,shuffle

t = 100000 #randint(1, 100000)

print(t)

numberL = list('12345678')
letterL = list('abcdefgh')
for i in range(t):
    shuffle(numberL)
    shuffle(letterL)
    
    firstLoc = letterL[0] + numberL[0]
    secondLoc = letterL[1] + numberL[1]
    print(firstLoc + " " + secondLoc)

