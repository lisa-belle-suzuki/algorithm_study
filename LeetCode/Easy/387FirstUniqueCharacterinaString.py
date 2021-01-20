class Solution:
    def firstUniqChar(self, s: str) -> int:
        cnt = [0] * 26
        for c in s:
            idx = ord(c) - ord('a')
            cnt[idx] += 1

        for i in range(len(s)):
            c = s[i]
            idx = ord(c) - ord('a')
            if cnt[idx] == 1:
                return i

        return -1
