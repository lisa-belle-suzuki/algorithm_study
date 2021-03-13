class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        visited = [False] * 1001
        for i in range(len(arr)):
            visited[arr[i]] = True
        cnt = 0
        for i in range(1, len(visited)):
            if visited[i] == False:
                cnt += 1
                if cnt == k:
                    return i
        return len(visited)-1 + (k - cnt)
