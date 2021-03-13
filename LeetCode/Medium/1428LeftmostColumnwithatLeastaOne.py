# """
# This is BinaryMatrix's API interface.
# You should not implement it, or speculate about its implementation
# """
# class BinaryMatrix(object):
#    def get(self, row: int, col: int) -> int:
#    def dimensions(self) -> list[]:

class Solution:
    def leftMostColumnWithOne(self, binaryMatrix: 'BinaryMatrix') -> int:
        h, w = binaryMatrix.dimensions()
        # 半分に絞る
        cnt = 0
        isIncludeOne = {}
        for i in range(h):
            if binaryMatrix.get(i, w//2) == 1:
                cnt += 1

        def decideIncludeOne(col):
            if col in isIncludeOne:
                return isIncludeOne[col]
            for i in range(h):
                if binaryMatrix.get(i, col) == 1:
                    return True
            return False

        if cnt > 0:
            # 左半分を探索
            # 二分探索して，1を含まなくなるところを探す
            l = 0
            r = w//2
        else:
            # 右半分を探索
            l = w//2+1
            r = w-1
        while l <= r:
            c = (l+r)//2
            if decideIncludeOne(c):
                if c == 0:
                    return 0
                if decideIncludeOne(c-1):
                    r = c - 1
                else:
                    return c
            else:
                l = c + 1
        return -1
