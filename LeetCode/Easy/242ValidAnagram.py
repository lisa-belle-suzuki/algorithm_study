class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        cnt_s = [0] * 26
        cnt_t = [0] * 26

        if len(s) != len(t):
            return False

        for c_s in s:
            idx = ord(c_s) - ord('a')
            cnt_s[idx] += 1
        for c_t in t:
            idx = ord(c_t) - ord('a')
            cnt_t[idx] += 1

        for i in range(26):
            if cnt_s[i] != cnt_t[i]:
                return False

        return True
