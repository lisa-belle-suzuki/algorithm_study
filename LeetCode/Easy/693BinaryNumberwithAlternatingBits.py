class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        bit_str = format(n, 'b')
        prev = bit_str[0]
        for cur in bit_str[1:]:
            if cur == prev:
                return False
            prev = cur
        return True
