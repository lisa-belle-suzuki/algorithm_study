from collections import deque


class MovingAverage:

    def __init__(self, size: int):
        """
        Initialize your data structure here.
        """
        self.queue = deque()
        self.num = 0
        self.window_size = size

    def next(self, val: int) -> float:
        self.queue.append(val)
        self.num += 1
        if self.num > self.window_size:
            self.num -= 1
            self.queue.popleft()
        return sum(self.queue) / self.num


# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)
