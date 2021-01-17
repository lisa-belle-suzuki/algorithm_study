class Solution:
    def findMissingRanges(self, nums: List[int], lower: int, upper: int) -> List[str]:
        ans = []
        ans_tail = []

        if len(nums) == 0:
            if upper == lower:
                return [str(upper)]
            else:
                return [str(lower) + "->" + str(upper)]

        if nums[0] != lower:
            if nums[0] - lower == 1:
                ans.append(str(lower))
            else:
                ans.append(str(lower) + "->" + str(nums[0] - 1))
        if nums[-1] != upper:
            if upper - nums[-1] == 1:
                ans_tail.append(str(upper))
            else:
                ans_tail.append(str(nums[-1] + 1) + "->" + str(upper))

        if len(nums) == 1:
            return ans + ans_tail


        for i in range(1, len(nums)):
            if nums[i] == lower:
                continue
            if nums[i] - nums[i-1] == 1:
                continue
            if nums[i] - nums[i-1] == 2:
                ans.append(str(nums[i]-1))
            else:
                ans.append(str(nums[i-1]+1) + "->" + str(nums[i]-1))

        return ans + ans_tail