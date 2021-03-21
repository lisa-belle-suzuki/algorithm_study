from collections import defaultdict

N = int(input())
A = list(map(int, input().split()))


sub = defaultdict(int)
for i, a in enumerate(A):
    sub[a] += 1

for i in range(1, N+1):
    print(sub[i])
