class Solution:
    def findComplement(self, num: int) -> int:
        bit_str = ""
        while num > 0:
            if num & 1 == 0:
                # 0
                bit_str += '1'
            else:
                # 1
                bit_str += '0'
            num >>= 1
        bit_str = bit_str[::-1]
        return int(bit_str, 2)
