class Solution:
    def maxDepth(self, s: str) -> int:
        cnt = 0
        max_cnt = 0
        for c in s:
            if c == '(':
                cnt += 1
            elif c == ')':
                cnt -= 1
            max_cnt = max(cnt, max_cnt)
        return max_cnt
