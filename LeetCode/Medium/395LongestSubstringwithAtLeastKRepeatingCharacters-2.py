def longestSubstringUtil(s: str, start: int, end: int, k: int):
    if end < k:
        return 0
    count_map = [0] * 26
    for i in range(start, end):
        count_map[ord(s[i]) - ord('a')] += 1
    for mid in range(start, end):
        if count_map[ord(s[mid]) - ord('a')] >= k: continue
        midNext = mid + 1
        while midNext < end and count_map[ord(s[midNext]) - ord('a')] < k:
            midNext += 1
        return max(longestSubstringUtil(s, start, mid, k),
                  longestSubstringUtil(s, midNext, end, k))
    return end - start


class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        n = len(s)
        return longestSubstringUtil(s, 0, n, k)
