class Solution:
    def hammingWeight(self, n: int) -> int:
        original_str = bin(n)[2:]

        cnt = 0
        for c in original_str:
            if c == '1':
                cnt += 1

        return cnt