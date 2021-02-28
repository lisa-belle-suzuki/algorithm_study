import heapq
class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        N = len(matrix)
        minHeap = []
        for r in range(min(k, N)):
            minHeap.append((matrix[r][0], r, 0))

        heapq.heapify(minHeap)

        while k:
            element, r, c = heapq.heappop(minHeap)
            if c < N-1:
                heapq.heappush(minHeap, (matrix[r][c+1], r, c+1))
            k -= 1

        return element


class Solution2:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        N = len(matrix)
        minHeap = []
        for r in range(min(k, N)):
            minHeap.append((matrix[r][0], 0, r))

        heapq.heapify(minHeap)

        while k:
            element, c, r = heapq.heappop(minHeap)
            if c < N-1:
                heapq.heappush(minHeap, (matrix[r][c+1], c+1, r))
            k -= 1

        return element
