class Solution:
    def countArrangement(self, n: int) -> int:
        cnt = 0

        def isOkay(num, i):
            if num == 0:
                return True
            if num % i == 0:
                return True
            if i % num == 0:
                return True
            return False

        def search(cur, rest):
            nonlocal cnt
            if len(cur) == n:
                cnt += 1
                return
            for i, r in enumerate(rest):
                if isOkay(r, len(cur)+1):
                    search(cur + [r], rest[:i]+rest[i+1:])
            return

        search([], [i for i in range(1, n+1)])
        return cnt
