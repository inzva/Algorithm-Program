# Thanks skr for this solution.
import os
import sys

MOD = 1000000007

facts = [1]
for i in xrange(1, 1000001):
    facts.append((facts[-1] * i) % MOD)

def solve(n, m):
    mon, mox = sorted([n, m])
    result = 1
    
    for i in xrange(mox):
        diag_length = i+1
        if i+1 > mon:
            diag_length = mon
        
        result *= facts[diag_length]
        result %= MOD
    
    for i in xrange(1, mon):
        result *= facts[i]
        result %= MOD
    
    return result

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    
    nm = raw_input().split()
    
    n = int(nm[0])
    
    m = int(nm[1])
    
    result = solve(n, m)
    
    fptr.write(str(result) + '\n')
    
    fptr.close()


