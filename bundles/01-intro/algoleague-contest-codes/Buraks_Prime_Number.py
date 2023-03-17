
def check(n):
    i = 2
    while i * i <= n:
        if n % i == 0:
            return False
        i += 1
    return True

for i in xrange(int(raw_input())):
    print "Prime" if check(int(raw_input())) else "Not Prime"


