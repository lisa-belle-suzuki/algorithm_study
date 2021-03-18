N = int(input())

D = 1000000000 + 7


def calc(num, p):
    ret = 1
    for _ in range(p):
        ret = (ret * num) % D
    return ret


ans = calc(10, N) + calc(8, N) - calc(9, N) - calc(9, N)
ans %= D
print(ans)
