class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        sorted_nums = sorted(nums)
        cnt = 1
        if len(nums) == 1:
            return nums[0]
        for i in range(1, len(nums)):
            if sorted_nums[i] != sorted_nums[i-1]:
                if cnt == 1:
                    return sorted_nums[i-1]
                else:
                    cnt = 1
            else:
                cnt += 1
        return sorted_nums[-1]
