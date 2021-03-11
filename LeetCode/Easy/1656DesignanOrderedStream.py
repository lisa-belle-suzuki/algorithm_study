class OrderedStream:

    def __init__(self, n: int):
        self.values = [""] * n
        self.ptr = 0

    def insert(self, idKey: int, value: str) -> List[str]:
        self.values[idKey-1] = value
        if self.values[self.ptr] == "":
            return []

        ret = []
        while self.ptr < len(self.values) and self.values[self.ptr] != "":
            ret.append(self.values[self.ptr])
            self.ptr += 1
        return ret


# Your OrderedStream object will be instantiated and called as such:
# obj = OrderedStream(n)
# param_1 = obj.insert(idKey,value)
