from heapq import heappop, heappush


class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        numbers = []
        for i in range(1, n+1):
            heappush(numbers, str(i))
        ret = []
        while numbers:
            s = heappop(numbers)
            ret.append(int(s))
        return ret
