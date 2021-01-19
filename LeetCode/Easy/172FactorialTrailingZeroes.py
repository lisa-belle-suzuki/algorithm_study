class Solution:
    def trailingZeroes(self, n: int) -> int:
        if n == 0:
            return 0
        calc = 1
        i = 1
        while i <= n:
            calc *= i
            i += 1

        cnt = 0
        while calc % 10 == 0:
            calc //= 10
            cnt += 1

        return cnt
