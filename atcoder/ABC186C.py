N = int(input())
cnt = 0


def isOkay(num: int) -> bool:
    # 10進法
    num_ = num
    while num_ > 0:
        if num_ % 10 == 7:
            return False
        num_ //= 10
    # 8進法
    num_ = num
    while num_ > 0:
        if num_ % 8 == 7:
            return False
        num_ //= 8

    return True


for i in range(1, N+1):
    if isOkay(i):
        cnt += 1
print(cnt)
