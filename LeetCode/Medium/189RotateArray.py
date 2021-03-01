from copy import deepcopy
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        N = len(nums)
        ans = [0] * N

        for i,num in enumerate(nums):
            if i<k: ans[i] = nums[N-k+i]
            else: ans[i] = nums[i-k]

        for i in range(N):
            nums[i] = ans[i]
