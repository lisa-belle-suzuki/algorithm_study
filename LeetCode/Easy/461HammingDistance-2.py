class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        xor = x ^ y
        cnt = 0
        while xor:
            cnt += 1
            xor = xor & (xor-1) # Brian Kernighan's Algorithm
        return cnt
