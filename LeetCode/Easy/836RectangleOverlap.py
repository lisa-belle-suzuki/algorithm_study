class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        # rec2の4つの座標のうちどれかが，rec1の内部にある
        X1, Y1, X2, Y2 = rec1
        x1, y1, x2, y2 = rec2
        if X1 == X2 or Y1 == Y2 or x1 == x2 or y1 == y2:
            return False

        # 縦幅に被りがあるかどうか
        def overlapLevel(l, r, L, R):
            if L <= l < R or L < r <= R:
                return 2
            if l <= L < r or l < R <= r:
                return 2
            if l == R or r == L:
                return 1
            return 0

        x_level = overlapLevel(x1, x2, X1, X2)
        y_level = overlapLevel(y1, y2, Y1, Y2)
        if x_level == 2 and y_level == 2:
            return True
        return False
