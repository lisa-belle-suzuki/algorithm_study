class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        if n == 0:
            return len(tasks)
        cnt = [0] * 26
        for t in tasks:
            cnt[ord(t)-ord("A")] += 1
        cnt.sort(reverse=True)
        ans = 0
        while sum(cnt) > 0:
            i = 0
            while i < n + 1:
                if i >= 26 or cnt[i] == 0:
                    break
                cnt[i] -= 1
                # print("visit", chr(i + ord('A')))
                ans += 1
                i += 1
            if i < n+1 and sum(cnt) > 0:
                ans += (n+1 - i)
                # for _ in range(n+1-i): print("idle")
            cnt.sort(reverse=True)
        return ans
