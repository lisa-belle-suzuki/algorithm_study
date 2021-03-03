class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        def calc_area(start, end):
            if start > end: return 0
            min_idx = start
            for i in range(start, end+1):
                if heights[i] < heights[min_idx]:
                    min_idx = i
            return max(
                heights[min_idx] * (end-start+1),
                calc_area(start, min_idx-1),
                calc_area(min_idx+1, end)
            )

        return calc_area(0, len(heights)-1)
