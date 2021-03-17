h, w = list(map(int, input().split()))
S = []
for _ in range(h):
    s = input()
    S.append(s)


# print(S)
d = [(0, 0), (0, 1), (1, 0), (1, 1)]
ans = 0
for i in range(h-1):
    for j in range(w-1):
        cnt = 0
        # print(i, j)
        for (di, dj) in d:
            if S[i+di][j+dj] == '#':
                cnt += 1
        if cnt in [1, 3]:
            ans += 1
print(ans)
