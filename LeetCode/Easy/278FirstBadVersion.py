# The isBadVersion API is already defined for you.
# @param version, an integer
# @return an integer
# def isBadVersion(version):

class Solution:
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        l = 1
        r = n
        while l <= r:
            c = (l+r)//2
            if c == 0:
                if isBadVersion(0):
                    return 0
                else:
                    l = c + 1
            if not isBadVersion(c-1):
                if isBadVersion(c):
                    return c
                else:
                    l = c + 1
            else:  # isBadVersion(n-1)
                r = c - 1
        return n+1
