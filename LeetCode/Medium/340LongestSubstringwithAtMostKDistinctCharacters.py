class Solution:
    def lengthOfLongestSubstringKDistinct(self, s: str, k: int) -> int:
        cnt_dict = {} # char: (cnt, last_idx)

        def find_key_at_min_last_idx():
            min_last_idx = float('inf')
            min_key = None
            for k in cnt_dict.keys():
                last_idx = cnt_dict[k][1]
                if last_idx < min_last_idx:
                    min_last_idx = min(min_last_idx, last_idx)
                    min_key = k
            return min_key

        left = 0
        right = 0
        longest = 0
        while right < len(s):
            c = s[right]
            if c not in cnt_dict: cnt_dict[c] = [1, right]
            else:
                cnt_dict[c][0] += 1
                cnt_dict[c][1] = right
            if len(cnt_dict)>k:
                # last_idxが最小のものを探す
                min_key = find_key_at_min_last_idx()
                # leftをズラす
                left = cnt_dict[min_key][1]+1
                # dictから，last_idxが最小のものを削除
                cnt_dict.pop(min_key)
            longest = max(longest, right - left + 1)
            right += 1
        return longest
