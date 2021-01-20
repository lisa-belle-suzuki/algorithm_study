class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        cnt_zero = 0
        for i in range(len(nums)):
            num = nums[i]
            if num ==  0:
                cnt_zero += 1
            else:
                nums[i-cnt_zero] = nums[i]

        for i in range(1,cnt_zero+1):
            nums[-i] = 0
        return
