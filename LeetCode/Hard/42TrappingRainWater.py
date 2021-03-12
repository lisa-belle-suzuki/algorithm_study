class Solution:
    def trap(self, height: List[int]) -> int:
        idx_map = defaultdict(list)
        sorted_height = sorted(height, reverse=True)
        # idx map (num -> idx)を作っておく
        for i, h in enumerate(height):
            idx_map[h].append(i)
        # heightに出てきた高さを，最大値から取り出す
        i = 0
        ans = 0
        left_max = len(height)
        right_max = -1
        while i < len(sorted_height):
            # 各高さについて，水が溜まる量を加算する
            cur = sorted_height[i]
            l = idx_map[cur][0]
            r = idx_map[cur][-1]
            if l < left_max:
                left_max = l
            if r > right_max:
                right_max = r
            i += len(idx_map[cur])
            if left_max == right_max:
                continue
            for j in range(left_max+1, right_max):
                if height[j] < cur:
                    ans += (cur - height[j])
                    height[j] = cur
        return ans
