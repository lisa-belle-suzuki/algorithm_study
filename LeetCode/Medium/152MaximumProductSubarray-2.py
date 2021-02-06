class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if len(nums)==0:
            return 0
        max_so_far = nums[0]
        min_so_far = nums[0]
        cur_max = max_so_far

        for i in range(1, len(nums)):
            cur = nums[i]
            temp_max = max(cur, max_so_far*cur, min_so_far*cur)
            min_so_far = min(cur, max_so_far*cur, min_so_far*cur)
            max_so_far = temp_max
            cur_max = max(max_so_far, cur_max)
        return cur_max
