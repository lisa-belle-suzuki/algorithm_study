class Solution:
    def removeVowels(self, s: str) -> str:
        new_s = ''
        for c in s:
            if c not in ['a', 'e', 'i', 'o', 'u']:
                new_s += c
        return new_s
