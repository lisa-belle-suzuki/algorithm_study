class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        starts = [0] * len(intervals)
        ends = [0] * len(intervals)
        for i in range(len(intervals)):
            starts[i], ends[i] = intervals[i]
        starts.sort()
        ends.sort()

        cnt = 0
        cnt_list = []
        j = 0
        for i in range(len(starts)):
            cnt += 1
            if starts[i] >= ends[j]:
                cnt -= 1
                j += 1
            cnt_list.append(cnt)
        return max(cnt_list)
