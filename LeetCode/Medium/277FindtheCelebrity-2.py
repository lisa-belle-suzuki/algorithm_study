# The knows API is already defined for you.
# return a bool, whether a knows b
# def knows(a: int, b: int) -> bool:
from functools import lru_cache

class Solution:
    def findCelebrity(self, n: int) -> int:
        self.n = n
        candidate = 0
        for j in range(1, n):
            if self.cachedKnows(candidate, j):
                candidate = j
        if self.isCelebrity(candidate):
            return candidate
        return -1

    @lru_cache(maxsize=None)
    def cachedKnows(self, a, b):
        return knows(a, b)

    def isCelebrity(self, i):
        for j in range(self.n):
            if i==j: continue
            if self.cachedKnows(i, j) or not self.cachedKnows(j, i):
                return False
        return True
