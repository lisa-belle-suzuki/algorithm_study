class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        N = len(nums)
        k %= N
        add = nums[:N-k]
        nums[:k] = nums[N-k:]
        nums[k:] = add[:N-k]
