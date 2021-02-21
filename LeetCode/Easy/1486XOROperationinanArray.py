class Solution:
    def xorOperation(self, n: int, start: int) -> int:
        ret = start
        cur = start
        for _ in range(n-1):
            cur += 2
            ret ^= cur
        return ret
