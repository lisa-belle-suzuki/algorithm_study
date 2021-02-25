class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        # count_map = [0] * 26
        max_unique = self.getMaxUniqueLetters(s)
        result = 0
        for cur_unique in range(1, max_unique + 1):
            count_map = [0] * 26
            window_s = 0
            window_e = 0
            idx = 0
            unique = 0
            count_atleast_k = 0
            while window_e < len(s):
                if unique <= cur_unique:
                    idx = ord(s[window_e]) - ord('a')
                    if count_map[idx] == 0:
                        unique += 1
                    count_map[idx] +=1
                    if count_map[idx] == k:
                        count_atleast_k += 1
                    window_e += 1
                else:
                    idx = ord(s[window_s]) - ord('a')
                    if count_map[idx] == k:
                        count_atleast_k -= 1
                    count_map[idx] -= 1
                    if count_map[idx] == 0:
                        unique -= 1
                    window_s += 1
                if unique == cur_unique and unique == count_atleast_k:
                    result = max(window_e - window_s, result)
        return result

    def getMaxUniqueLetters(self, s: str):
        map_ = [False] * 26
        max_unique = 0
        for i in range(len(s)):
            if not map_[ord(s[i])-ord('a')]:
                max_unique += 1
                map_[ord(s[i])-ord('a')] = True
        return max_unique
