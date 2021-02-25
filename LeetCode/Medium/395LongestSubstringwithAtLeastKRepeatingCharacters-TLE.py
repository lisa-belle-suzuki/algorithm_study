from copy import deepcopy
class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        cnt = [0] * 26

        cnt_memo = [[]] * len(s)
        for i in range(len(s)):
            idx = ord(s[i]) - ord('a')
            cnt[idx] += 1
            cnt_memo[i] = deepcopy(cnt)

        max_len = 0

        for j in range(len(s)):
            for i in range(j+1):
                isValid = True
                if i==0:
                    for e in cnt_memo[j]:
                        if e!=0 and e < k:
                            isValid = False
                            break
                else:
                    for s,e in zip(cnt_memo[i-1], cnt_memo[j]):
                        diff = e - s
                        if diff!=0 and diff < k:
                            isValid = False
                            break
                if isValid == True:
                    max_len = max(max_len, j-i+1)
        return max_len
