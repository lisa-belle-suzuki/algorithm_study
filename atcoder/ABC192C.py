n, k = list(map(int, input().split()))


def g1(x: int) -> int:
    nums = []
    while x > 0:
        nums.append(x % 10)
        x //= 10
    nums.sort(reverse=True)
    ret = 0
    for num in nums:
        ret += num
        ret *= 10
    return ret//10


def g2(x: int) -> int:
    nums = []
    while x > 0:
        nums.append(x % 10)
        x //= 10
    nums.sort()
    ret = 0
    for num in nums:
        if num == 0:
            continue
        ret += num
        ret *= 10
    return ret//10


def f(x: int) -> int:
    return g1(x) - g2(x)


cur = n
for _ in range(k):
    cur = f(cur)
print(cur)
