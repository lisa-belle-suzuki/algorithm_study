N = int(input())
X = []
Y = []
for i in range(N):
    x, y = map(int, input().split())
    X.append(x)
    Y.append(y)


def on_same_line(p1, p2, p3):
    if p1[0] == p2[0] == p3[0]:
        return True
    if p1[1] == p2[1] == p3[1]:
        return True
    if p3[0] == p2[0] or p2[0] == p1[0]:
        return False
    if (p3[1]-p2[1])/(p3[0]-p2[0]) == (p2[1]-p1[1])/(p2[0]-p1[0]):
        return True
    else:
        return False


def solve():
    for i in range(N-2):
        for j in range(i+1, N-1):
            for k in range(j+1, N):
                if on_same_line(
                    (X[i], Y[i]),
                    (X[j], Y[j]),
                    (X[k], Y[k])
                ):
                    print('Yes')
                    return
    print("No")
    return


solve()
