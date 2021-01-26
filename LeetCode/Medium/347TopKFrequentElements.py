import heapq
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        num_set = set()
        counter = {}
        for num in nums:
            if num in counter:
                counter[num] += 1
            else:
                counter[num] = 1
            num_set.add(num)

        numbers = []
        for num in num_set:
            cnt = counter[num]
            heapq.heappush(numbers, (-cnt, num))

        ans = []
        for _ in range(k):
            num = heapq.heappop(numbers)
            ans.append(num[1])
        return ans
