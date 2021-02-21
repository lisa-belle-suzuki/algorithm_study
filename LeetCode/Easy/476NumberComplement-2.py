from math import log2
class Solution:
    def findComplement(self, num: int) -> int:
        n = floor(log2(num)) + 1
        bitmask = (1 << n) - 1
        return bitmask ^ num
