import heapq


class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        N = len(nums)
        squares = []
        l = bisect.bisect_left(nums, 0)
        r = bisect.bisect_right(nums, 0)
        for _ in range(l, r):
            squares.append(0)
        l -= 1
        while l >= 0 or r < N:
            if l < 0:
                squares.append(nums[r] ** 2)
                r += 1
            elif r >= N:
                squares.append(nums[l] ** 2)
                l -= 1
            else:
                if abs(nums[l]) < abs(nums[r]):
                    squares.append(nums[l] ** 2)
                    l -= 1
                else:
                    squares.append(nums[r] ** 2)
                    r += 1
        return squares
