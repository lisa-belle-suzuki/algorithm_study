from collections import deque


class Solution:
    def longestPalindrome(self, s: str) -> str:
        N = len(s)

        if N == 1:
            return s

        q = deque()
        # 1文字
        for i in range(N):
            q.append((i, i))
        # 2文字
        for i in range(len(s)-1):
            if s[i] == s[i+1]:
                q.append((i, i+1))

        # 3文字以上
        max_str = ""
        while q:
            cur = q.popleft()
            l, r = cur
            if r-l+1 > len(max_str):
                max_str = s[l:r+1]

            if (r-l+1) == len(s):
                break
            if l <= 0 or r >= len(s)-1:
                continue
            if s[l-1] == s[r+1]:
                q.append((l-1, r+1))

        return max_str
