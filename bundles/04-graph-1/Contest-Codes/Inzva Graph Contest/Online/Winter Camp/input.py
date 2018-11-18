from random import randint, shuffle

t = 3 #randint(1, 20)

print(t)
for i in range(t):
    n = randint(1, 10)
    m = [0, 7, 14, 21, 28, 35, 42][randint(0, 6)]
    print(n, m)

    sizeList = ['XXS' ,'XS', 'S', 'M', 'L', 'XL', 'XXL']
    for i in range(n):
        shuffle(sizeList)
        x = sizeList[0]
        y = sizeList[1]
        z = sizeList[2]
        print(x, y, z)
