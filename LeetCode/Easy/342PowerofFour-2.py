class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        if n <= 0: return False
        else:
            bitmask = 0b101010101010101010101010101010101
            if bitmask | n != bitmask:
                return False
            if n - (n & -n) == 0:
                return True
            else:
                return False
