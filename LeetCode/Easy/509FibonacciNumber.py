class Solution:
    def __init__(self):
        self.memo = {}

    def fib(self, n: int) -> int:
        if n in self.memo:
            return self.memo[n]
        if n == 0:
            return 0
        if n == 1:
            return 1
        ans = self.fib(n-1) + self.fib(n-2)
        self.memo[n] = ans
        return ans
