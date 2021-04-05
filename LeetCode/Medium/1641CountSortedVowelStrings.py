from collections import deque


class Solution:
    def countVowelStrings(self, n: int) -> int:
        cnt = 0
        q = deque()
        q.append("")
        while q:
            cur = q.popleft()
            if len(cur) == 0:
                q.append("a")
                q.append("e")
                q.append("i")
                q.append("o")
                q.append("u")
                continue
            if len(cur) == n:
                cnt += 1
                continue
            if cur[-1] == 'a':
                q.append(cur + 'a')
                q.append(cur + 'e')
                q.append(cur + 'i')
                q.append(cur + 'o')
                q.append(cur + 'u')
            elif cur[-1] == 'e':
                q.append(cur + 'e')
                q.append(cur + 'i')
                q.append(cur + 'o')
                q.append(cur + 'u')
            elif cur[-1] == 'i':
                q.append(cur + 'i')
                q.append(cur + 'o')
                q.append(cur + 'u')
            elif cur[-1] == 'o':
                q.append(cur + 'o')
                q.append(cur + 'u')
            elif cur[-1] == 'u':
                q.append(cur + 'u')

        return cnt
