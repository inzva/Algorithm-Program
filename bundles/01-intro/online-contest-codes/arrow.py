from collections import deque, defaultdict

N = int(raw_input())
A = map(lambda (i, x): (int(x), i), enumerate(raw_input().split()))
A.sort(key=lambda x: -x[0])

D = defaultdict(deque)

ans = 0
for x, i in A:
    if D[x + 1] and D[x + 1][0] < i:
        D[x + 1].popleft()
    else:
        ans += 1
    D[x].append(i)

print ans
