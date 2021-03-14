class Solution:
    def maxLength(self, arr: List[str]) -> int:
        # 全探索したら間に合わないな
        stack = [([0] * 26, 0)]  # (count list, next_idx)
        max_len = 0
        while stack:
            cnt_list, idx = stack.pop()
            if idx >= len(arr):
                continue

            stack.append((cnt_list, idx+1))
            new_cnt_list = []
            new_cnt_list[::] = cnt_list[::]
            for c in arr[idx]:
                new_cnt_list[ord(c)-ord('a')] += 1
            isOkay = True
            for cnt in new_cnt_list:
                if cnt > 1:
                    isOkay = False
                    break
            if isOkay:
                max_len = max(max_len, sum(new_cnt_list))
            else:
                continue
            stack.append((new_cnt_list, idx+1))

        return max_len
