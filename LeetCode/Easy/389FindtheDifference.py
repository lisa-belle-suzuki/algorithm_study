class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        s = sorted(s)
        t = sorted(t)
        for c_s, c_t in zip(s,t):
            if c_s!=c_t:
                return c_t
        return t[-1]
