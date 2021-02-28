import heapq

class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        nums = []
        N = len(matrix)
        for i in range(N):
            for j in range(N):
                heapq.heappush(nums, matrix[i][j])
        for _ in range(k-1):
            heapq.heappop(nums)
        return heapq.heappop(nums)
