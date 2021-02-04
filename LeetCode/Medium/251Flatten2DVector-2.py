class Vector2D:

    def __init__(self, v: List[List[int]]):
        self.v = v
        self.i = 0
        self.j = -1
        self.H = len(v)
        self.next_i = None
        self.next_j = None


    def next(self) -> int:
        if self.hasNext():
            self.i = self.next_i
            self.j = self.next_j
            return self.v[self.i][self.j]
        else:
            return -1


    def hasNext(self) -> bool:
        i = self.i
        j = self.j
        j += 1
        while 1:
            if i >= self.H:
                return False
            if j < len(self.v[i]):
                self.next_i = i
                self.next_j = j
                return True
            i += 1
            j = 0


# Your Vector2D object will be instantiated and called as such:
# obj = Vector2D(v)
# param_1 = obj.next()
# param_2 = obj.hasNext()