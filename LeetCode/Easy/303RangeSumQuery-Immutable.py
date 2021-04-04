class NumArray:

    def __init__(self, nums: List[int]):
        self.accum_sum = []
        s = 0
        for num in nums:
            s += num
            self.accum_sum.append(s)

    def sumRange(self, left: int, right: int) -> int:
        if left == 0:
            return self.accum_sum[right]
        return self.accum_sum[right] - self.accum_sum[left-1]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)
