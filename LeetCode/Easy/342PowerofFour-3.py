class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        if num <= 0:
            return False
        if num & (num - 1) != 0:
            # 2の累乗かどうかcheck
            return False
        return num % 3 == 1
