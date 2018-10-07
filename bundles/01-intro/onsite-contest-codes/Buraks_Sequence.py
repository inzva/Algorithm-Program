
N = int(raw_input())
A = map(int, raw_input().split())
S = 0

for index, item in enumerate(A):
    ans = item * (index + 1) - S
    S += ans
    print ans,
print
