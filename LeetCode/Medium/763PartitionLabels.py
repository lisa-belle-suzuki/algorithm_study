class Solution:
    def partitionLabels(self, S: str) -> List[int]:
        idx_map = defaultdict(list)
        for i, c in enumerate(S):
            idx_map[c].append(i)

        ans = []
        cur = 0
        start = 0
        while cur < len(S):
            max_idx = idx_map[S[cur]][-1]
            while cur <= max_idx:
                max_idx = max(idx_map[S[cur]][-1], max_idx)
                # print("max_idx:",max_idx)
                cur += 1
            # print("------")
            # print("cur:", cur)
            ans.append(cur - start)
            start = cur
        return ans
