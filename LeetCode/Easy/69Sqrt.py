class Solution:
    def mySqrt(self, x: int) -> int:
        left = 0
        right = x
        while(1):
            cent = (left + right) // 2
            if cent ** 2 > x:
                right = cent
            else:
                if (cent + 1) ** 2 > x:
                    return cent
                else:
                    left = cent + 1
