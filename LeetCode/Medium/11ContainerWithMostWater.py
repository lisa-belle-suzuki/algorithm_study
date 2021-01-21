class Solution:
    def maxArea(self, height: List[int]) -> int:
        # 普通にO(n^2)で解いたら時間オーバー
        # 逆にだんだん広げていく方法を思いついてしまったけど，だんだん狭めていく方法が良かったのね...(Approach2)
        i = 0
        j = len(height) - 1
        cur_max_area = 0
        while i < j:
            height_left = height[i]
            height_right = height[j]
            cur_area = (j - i) * min(height_left, height_right)
            if cur_area > cur_max_area:
                cur_max_area = cur_area

            if height_left <= height_right:
                i += 1
            else:
                j -= 1

        return cur_max_area
