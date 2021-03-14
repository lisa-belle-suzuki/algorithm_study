class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        count = 0
        prev = ""
        counter = []
        for i, c in enumerate(s):
            if c == prev:
                count += 1
            else:
                count %= k
                if count > 0:
                    counter.append((prev, count))
                if len(counter) > 0 and counter[-1][0] == c:
                    cur = counter.pop()
                    prev = cur[0]
                    count = cur[1] + 1
                else:
                    prev = c
                    count = 1

        count %= k
        if count > 0:
            counter.append((s[-1], count))

        ans = ""
        for pair in counter:
            char, cnt = pair
            for _ in range(cnt):
                ans += char
        return ans
