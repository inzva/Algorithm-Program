#!/bin/python
# Thanks skr for this solution.
import os
import sys

def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        return (g, x - (b // a) * y, y)

def modinv(a, m):
    g, x, y = egcd(a, m)
    if g != 1:
        raise Exception('modular inverse does not exist')
    else:
        return x % m

# Complete the solve function below.
def solve(p, q, n):
    MOD = 1000000007
    
    tx = (p * modinv(q, MOD)) % MOD
    
    if n == 1:
        return tx
    elif n%2 == 0:
        now = solve(p, q, n/2)
        return (2*now * modinv((1-now**2)%MOD, MOD)) % MOD
    else:
        now = solve(p, q, n/2)
        keep = (2*now * modinv((1-now**2)%MOD, MOD)) % MOD
        return ((tx + keep) * modinv((1-tx*keep)%MOD, MOD)) % MOD

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    
    t = int(raw_input())
    
    for t_itr in xrange(t):
        pqn = raw_input().split()
        
        p = int(pqn[0])
        
        q = int(pqn[1])
        
        n = int(pqn[2])
        
        result = solve(p, q, n)
        
        fptr.write(str(result) + '\n')
    
    fptr.close()


