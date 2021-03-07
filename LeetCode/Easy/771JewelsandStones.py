class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        jewel_set = set(jewels)
        cnt = 0
        for stone in stones:
            if stone in jewel_set: cnt += 1
        return cnt
