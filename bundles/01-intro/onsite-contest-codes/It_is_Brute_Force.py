
N = int(raw_input())
A = map(int, raw_input().split())
S = {0}

ans = float('inf')

for i in A:
    temp = set()
    for j in S:
        temp.add(i + j)
        ans = min(ans, abs(i + j))
    S.update(temp)
print ans
