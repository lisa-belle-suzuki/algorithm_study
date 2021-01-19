class Solution:
    def hammingWeight(self, n: int) -> int:
        print(bin(n))

        cnt = 0
        bit_mask = 1
        for i in range(32):
            if n & bit_mask:
                cnt += 1
            n >>= 1

        return cnt