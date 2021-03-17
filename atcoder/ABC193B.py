n = int(input())
a1 = (-1, float('inf'))
a2 = (-1, float('inf'))
b1 = (-1, float('inf'))
b2 = (-1, float('inf'))

for i in range(n):
    a, b = list(map(int, input().split()))
    if a <= a1[1]:
        a2 = a1
        a1 = (i, a)
    elif a < a2[1]:
        a2 = (i, a)
    if b <= b1[1]:
        b2 = b1
        b1 = (i, b)
    elif b < b2[1]:
        b2 = (i, b)

if a1[0] == b1[0]:
    ans = min([
        a1[1] + b1[1],
        max(a1[1], b2[1]),
        max(a2[1], b1[1])
    ])
    print(ans)
else:
    print(max(a1[1], b1[1]))
