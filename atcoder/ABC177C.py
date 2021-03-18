N = int(input())
A = list(map(int, input().split()))
sum_list = []

D = 1000000000 + 7

sum_ = 0
for a in A:
    sum_ += a
    sum_list.append(sum_)

ans = 0
for i in range(N):
    ans += (sum_list[N-1]-sum_list[i]) * A[i]
    ans %= D

print(ans)
