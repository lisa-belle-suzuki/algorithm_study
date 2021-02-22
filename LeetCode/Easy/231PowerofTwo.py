def is_power_of_two(positive_num):
    while positive_num > 0:
        if positive_num & 1 == 1:
            if positive_num >> 1 == 0: return True
            else: return False
        positive_num >>= 1
    return False

class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n == 0: return False
        elif n > 0:
            return is_power_of_two(n)
        else: # 負
            return False
