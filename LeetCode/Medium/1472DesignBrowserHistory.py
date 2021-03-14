class BrowserHistory:

    def __init__(self, homepage: str):
        self.homepage = homepage
        self.history = [homepage]
        self.ptr = 0

    def visit(self, url: str) -> None:
        if self.ptr < len(self.history)-1:
            del self.history[self.ptr+1:]
        self.history.append(url)
        self.ptr += 1

    def back(self, steps: int) -> str:
        self.ptr -= steps
        if self.ptr < 0:
            self.ptr = 0
            return self.homepage
        else:
            return self.history[self.ptr]

    def forward(self, steps: int) -> str:
        self.ptr += steps
        if self.ptr >= len(self.history):
            self.ptr = len(self.history)-1
            return self.history[self.ptr]
        else:
            return self.history[self.ptr]


# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)
