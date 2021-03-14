class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.split(' ')
        return ' '.join([w for w in words[::-1] if len(w) > 0])
