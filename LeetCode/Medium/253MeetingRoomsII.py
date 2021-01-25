def idx_in_list(tgt, nums):
    l = 0
    r = len(nums)-1
    while l<=r:
        c = (l+r)//2
        if nums[c] == tgt:
            return c
        elif nums[c] < tgt:
            l = c + 1
        elif nums[c] > tgt:
            r = c - 1
    return -1 # not found

class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        separate_set = set()
        for interval in intervals:
            separate_set.add(interval[0])
            separate_set.add(interval[1])

        separate_set = list(separate_set)
        separate_set.sort()

        cnt = [0] * len(separate_set)
        for interval in intervals:
            L,R = interval
            L_idx = idx_in_list(L, separate_set)
            R_idx = idx_in_list(R, separate_set)
            for i in range(L_idx, R_idx):
                cnt[i] += 1

        return max(cnt)
