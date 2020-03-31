from random import randint

n = 40000 # randint(0, 100000)
m = 100000 # randint(0, 10000)
print(n, m)
for i in range(m):
    if(i < m/2):
        t = 1
    else:
        t = 2
# t = i%2 + 1
    a = randint(1, n)
    b = randint(1, n)

    print(t, a, b)
