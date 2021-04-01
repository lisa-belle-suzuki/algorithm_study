class Solution:
    def isArmstrong(self, n: int) -> bool:
        k = len(str(n))
        s = 0
        for c in str(n):
            s += int(c)**k
        return s == n
