def solve():
    N = int(input())
    A = list(map(int, input().split()))
    if 0 in A:
        print(0)
        return
    ans = 1
    for i in range(len(A)):
        ans *= A[i]
        if ans > 1000000000000000000:
            print(-1)
            return
    print(ans)
    return


solve()