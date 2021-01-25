class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        from_left = []
        cur = 1
        for num in nums:
            cur *= num
            from_left.append(cur)

        from_right = []
        cur = 1
        for i in range(len(nums)):
            cur *= nums[len(nums)-1-i]
            from_right.append(cur)
        from_right.reverse()

        ans = []
        for i in range(len(nums)):
            if i == 0:
                left_accum = 1
            else:
                left_accum = from_left[i-1]
            if i == len(nums)-1:
                right_accum = 1
            else:
                right_accum = from_right[i+1]
            ans.append(left_accum * right_accum)
        return ans
