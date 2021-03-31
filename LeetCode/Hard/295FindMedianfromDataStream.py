class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        # nums
        self.nums = []

    def addNum(self, num: int) -> None:
        if len(self.nums) == 0:
            self.nums.append(num)
            return
        if num < self.nums[0]:
            self.nums = [num] + self.nums
            return
        if num > self.nums[-1]:
            self.nums.append(num)
            return
        # 二分探索
        l = 0
        r = len(self.nums)-1
        while l <= r:
            c = (l+r) // 2
            if num == self.nums[c]:
                self.nums = self.nums[:c] + [num] + self.nums[c:]
                return
            if num < self.nums[c]:
                if num > self.nums[c-1]:
                    self.nums = self.nums[:c] + [num] + self.nums[c:]
                    return
                else:
                    r = c - 1
            else:
                l = c + 1
        return

    def findMedian(self) -> float:
        # 中央値
        N = len(self.nums)
        if N == 0:
            return 0.0
        if N % 2 == 0:
            return (self.nums[N//2-1] + self.nums[N//2])/2.0
        else:
            return self.nums[N//2]


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
