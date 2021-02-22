class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        if n <= 0: return False
        if n > 0:
            while n > 0:
                if n & 0b11 == 1: # 下2桁
                    if (n >> 2) == 0: return True
                    else: return False
                elif n & 0b11 != 0: return False
                n >>= 2
        return False
