N = int(input())
without_exc = {}
with_exc = {}


def solve():
    ans = None
    for _ in range(N):
        S = input()
        if S[0] == '!':
            if S[1:] in without_exc:
                ans = S[1:]
            with_exc[S[1:]] = 1
        else:
            if S in with_exc:
                ans = S
            without_exc[S] = 1
    if ans is None:
        return "satisfiable"
    return ans


print(solve())
