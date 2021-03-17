N = input()
cnt = [0] * 3
bits = len(N)
sum_ = 0
for c in N:
    cnt[int(c) % 3] += 1
    sum_ += int(c) % 3
diff = sum_ % 3


def solve():
    if diff == 0:
        return 0
    elif diff == 1:
        if cnt[1] >= 1:
            return 1
        elif cnt[2] >= 2:
            return 2
        else:
            return -1
    else:
        if cnt[2] >= 1:
            return 1
        elif cnt[1] >= 2:
            return 2
        else:
            return -1


ans = solve()
if ans == bits:
    print(-1)
else:
    print(ans)
