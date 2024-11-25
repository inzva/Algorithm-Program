from math import ceil

N = int(raw_input())
M = int(raw_input())
K = int(raw_input())
A = [int(raw_input()) for i in xrange(M)]
A.sort()

ans = 0
cur = 0

for i in xrange(M):
    ans += int(ceil(max(A[i] - K - cur - 1, 0) / (2. * K + 1)))
    cur = A[i] + K

print ans + int(ceil(max(N - cur, 0) / (2. * K + 1)))