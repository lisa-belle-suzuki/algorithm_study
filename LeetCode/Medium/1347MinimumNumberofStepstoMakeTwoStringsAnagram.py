class Solution:
    def minSteps(self, s: str, t: str) -> int:
        s_cnt = [0] * 26
        t_cnt = [0] * 26
        for c in s:
            s_cnt[ord(c)-ord('a')] += 1
        for c in t:
            t_cnt[ord(c)-ord('a')] += 1

        ans = 0
        for i in range(26):
            diff = t_cnt[i] - s_cnt[i]
            if diff > 0:
                ans += diff

        return ans
