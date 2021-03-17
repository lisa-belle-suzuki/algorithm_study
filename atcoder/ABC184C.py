r1, c1 = map(int, input().split())
r2, c2 = map(int, input().split())

x_ = r2 - r1
y_ = c2 - c1


def search(x, y):
    if x == 0 and y == 0:
        return 0
    elif abs(x) == abs(y):
        return 1
    elif abs(x) + abs(y) <= 3:
        return 1
    #
    elif (x ^ y ^ 1) & 1:
        return 2
    elif abs(x) + abs(y) <= 6:
        return 2
    elif abs(x + y) <= 3 or abs(x - y) <= 3:
        return 2
    else:
        return 3


print(search(abs(x_), abs(y_)))
