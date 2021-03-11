class MovingAverage:

    def __init__(self, size: int):
        """
        Initialize your data structure here.
        """
        self.nums = [0] * size
        self.cur = 0
        self.size = size
        self.cnt = 0

    def next(self, val: int) -> float:
        if self.cur >= self.size:
            self.cur %= self.size
        self.nums[self.cur] = val
        if self.cnt < self.size:
            self.cnt += 1
        self.cur += 1
        return sum(self.nums) / self.cnt


# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)
