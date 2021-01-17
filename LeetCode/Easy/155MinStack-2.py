class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.nums = []
        self.min_nums = []

    def push(self, x: int) -> None:
        if len(self.nums) ==0:
            self.min_nums.append(x)
        else:
            if x < self.min_nums[-1]:
                self.min_nums.append(x)
            else:
                self.min_nums.append(self.min_nums[-1])

        self.nums.append(x)
        return

    def pop(self) -> None:
        del self.nums[-1]
        del self.min_nums[-1]
        return

    def top(self) -> int:
        return self.nums[-1]

    def getMin(self) -> int:
        return self.min_nums[-1]



# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()