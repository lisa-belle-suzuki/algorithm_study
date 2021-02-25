class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        cnt = [0] * 3
        for num in nums:
            cnt[num] += 1

        for i, num in enumerate(nums):
            if i in range(cnt[0]) and num!=0:
                nums[i] = 0
            if i in range(cnt[0], cnt[0]+cnt[1]) and num!=1:
                nums[i] = 1
            if i in range(cnt[0]+cnt[1], len(nums)) and num!=2:
                nums[i] = 2
