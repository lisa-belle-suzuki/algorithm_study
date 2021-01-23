class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        l = intervals[0][0]
        r = intervals[0][1]
        prev_l = l
        prev_r = r
        ans = []
        for i in range(1,len(intervals)):
            l = intervals[i][0]
            r = intervals[i][1]
            if l > prev_r:
                ans.append([prev_l, prev_r])
                prev_l = l
                prev_r = r
            else:
                if r > prev_r:
                    # merge
                    prev_r = r

        ans.append([prev_l, prev_r])
        return ans
