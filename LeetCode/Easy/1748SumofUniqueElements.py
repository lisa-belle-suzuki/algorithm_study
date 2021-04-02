class Solution:
    def sumOfUnique(self, nums: List[int]) -> int:
        visited = defaultdict(int)
        for num in nums:
            visited[num] += 1
        ret = 0
        for num in visited.keys():
            if visited[num] == 1:
                ret += num
        return ret
