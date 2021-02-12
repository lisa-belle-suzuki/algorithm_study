class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        ans = []
        n = target[-1]
        cur = target.pop()
        while 1:
            if cur == n:
                ans.append("Push")
                if len(target)==0:
                    break
                cur = target.pop()
            elif cur < n:
                ans.append("Pop")
                ans.append("Push")
            n -= 1
        while n > 1:
            ans.append("Pop")
            ans.append("Push")
            n -= 1
        return ans[::-1]
