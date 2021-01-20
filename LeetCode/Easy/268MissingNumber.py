class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        max_ = -1
        sum_ = 0
        isIncludedZero = False
        for num in nums:
            if num > max_:
                max_ = num
            sum_ += num
            if num == 0:
                isIncludedZero = True

        ans = max_ * (max_ + 1) // 2 - sum_
        if ans == 0 and isIncludedZero:
            return max_ + 1
        return ans
