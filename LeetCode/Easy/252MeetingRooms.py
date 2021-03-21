from heapq import heapify, heappop


class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
        prev = None
        heapify(intervals)
        while len(intervals) > 0:
            cur = heappop(intervals)
            if prev:
                if prev[1] > cur[0]:
                    return False
            prev = cur
        return True
