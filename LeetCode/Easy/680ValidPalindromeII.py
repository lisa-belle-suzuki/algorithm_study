class Solution:
    def validPalindrome(self, s: str) -> bool:
        stack = [(0, len(s)-1, False)]
        while stack:
            (l, r, hasDeleted) = stack.pop()
            if l >= r:
                return True
            if s[l] == s[r]:
                stack.append((l+1, r-1, hasDeleted))
            else:
                if hasDeleted:
                    continue
                stack.append((l+1, r, True))
                stack.append((l, r-1, True))

        return False
