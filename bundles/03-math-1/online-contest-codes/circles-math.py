# Thanks skr for this solution.
MOD = 1000000007

def modinv(n):
    return pow(n, MOD-2, MOD)

not_fixed_counts = [1, 0]
facts = [1, 1]
for i in xrange(2, 1000000):
    facts.append((facts[-1] * i) % MOD)
    not_fixed_counts.append((not_fixed_counts[-1]*i + (-1)**i) % MOD)

def subcall(n, k, q):
    return (facts[n] * modinv(facts[q] * facts[n-q*k] * pow(k, q, MOD)))


def maincall(n, k):
    som = 0
    for i in xrange(1, n/k+1):
        #print "--", subcall(n, k, i), not_fixed_count(n - k*i)
        som += ((-1)**(i+1) * subcall(n, k, i) * not_fixed_counts[n - k*i]) % MOD
        som %= MOD
    return som

T = input()
for t in xrange(T):
    n, k = map(int, raw_input().split(" "))
    
    if k <= 1:
        print 0
    else:
        print maincall(n, k)


