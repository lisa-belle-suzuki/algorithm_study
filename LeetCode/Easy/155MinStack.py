class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.nums = []

    def push(self, x: int) -> None:
        self.nums.append(x)
        return

    def pop(self) -> None:
        del self.nums[-1]
        return

    def top(self) -> int:
        return self.nums[-1]

    def getMin(self) -> int:
        cur_min = self.nums[0]
        for i in range(1, len(self.nums)):
            if self.nums[i] < cur_min:
                cur_min = self.nums[i]
        return cur_min



# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()