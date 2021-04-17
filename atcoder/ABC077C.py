N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))

A.sort()
B.sort()
C.sort()


def search(list_: [int], num: int):
    l = 0
    r = len(list_)-1
    while l <= r:
        c = (l+r)//2
        if c == 0:
            if list_[0] > num:
                return 0
            l = c + 1
        elif list_[c] > num:
            if list_[c-1] <= num:
                return c
            else:
                r = c - 1
        else:
            l = c + 1
    return -1


cnt = 0
for a in A:
    b_idx = search(B, a)
    if b_idx < 0:
        continue
    for i in range(b_idx, len(B)):
        c_idx = search(C, B[i])
        if c_idx < 0:
            continue
        cnt += (len(C)-c_idx)

print(cnt)
