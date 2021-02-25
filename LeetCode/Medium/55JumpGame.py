class Solution:
    def canJump(self, nums: List[int]) -> bool:
        cnt = 0
        for i, num in enumerate(nums):
            if i == len(nums)-1: return True
            max_jump = max(num, cnt)
            if max_jump == 0: return False
            cnt = max_jump - 1
        return True
