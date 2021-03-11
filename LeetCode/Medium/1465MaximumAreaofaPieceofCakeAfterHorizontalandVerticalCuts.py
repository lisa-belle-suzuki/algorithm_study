class Solution:
    def maxArea(self, h: int, w: int, horizontalCuts: List[int], verticalCuts: List[int]) -> int:
        horizontalCuts.sort()
        verticalCuts.sort()
        # 差分の最大値を求める

        def calc_max_diff(num_list, max_) -> int:
            max_diff = 0
            max_idx = -1
            max_diff = max(num_list[0], max_diff)
            max_diff = max(max_ - num_list[-1], max_diff)
            for i in range(len(num_list)-1):
                prev_diff = max_diff
                max_diff = max(num_list[i+1] - num_list[i], max_diff)
                if max_diff != prev_diff:
                    max_idx = i
            return max_diff
        max_h = calc_max_diff(horizontalCuts, h) % (10**9 + 7)
        max_w = calc_max_diff(verticalCuts, w) % (10**9 + 7)
        return (max_h * max_w) % (10**9 + 7)
