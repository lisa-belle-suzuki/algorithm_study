class Solution:
    def reverseBits(self, n: int) -> int:
        print(bin(n)[2:])
        original_str = bin(n)[2:] # 0bを除いた数
        if len(original_str) < 32:
            original_str = '0' * (32 - len(original_str)) + original_str # 0埋め

        i = 0
        twos = 1
        ans = 0

        while i < len(original_str):
            c = original_str[i]
            if c == '1':
                ans += twos
            twos *= 2
            i += 1

        return ans
