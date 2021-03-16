class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        ret = []
        sum_ = 0
        for num in nums:
            sum_ += num
            ret.append(sum_)
        return ret
