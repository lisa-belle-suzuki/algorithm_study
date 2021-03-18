N = int(input())
A = list(map(int, input().split()))

highests = []
h = -float('inf')
for a in A:
    h = max(h, a)
    highests.append(h)

ans = 0
for i in range(len(A)):
    ans += highests[i] - A[i]
print(ans)
