class Solution:
    def sumZero(self, n: int) -> List[int]:
        ret = []
        for i in range(1, n//2+1):
            ret.append(i)
            ret.append(-i)
        if n % 2 == 1:
            ret.append(0)
        return ret
