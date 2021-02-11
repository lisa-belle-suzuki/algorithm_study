import heapq
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        # solution1: sort
        # nums.sort(reverse=True)
        # return nums[k-1]

        # # solution2: heap
        # nums_new = [-num for num in nums]
        # heapq.heapify(nums_new)
        # for _ in range(k):
        #     ret = heapq.heappop(nums_new)
        # return -ret

        # solution3: QuickSelect using partition
        def partition(left, right, pivot_idx):
            pivot = nums[pivot_idx]
            # move pivot to end
            nums[pivot_idx], nums[right] = nums[right], nums[pivot_idx]

            # move all smaller elements to the left
            store_idx = left
            for i in range(left, right):
                if nums[i] < pivot:
                    nums[store_idx], nums[i] = nums[i], nums[store_idx]
                    store_idx += 1

            # move pivot to its final place
            nums[right], nums[store_idx] = nums[store_idx], nums[right]

            return store_idx

        def select(left, right, k_smallest):
            if left == right:
                return nums[left]
            pivot_idx = random.randint(left, right)
            pivot_idx = partition(left, right, pivot_idx)
            if k_smallest==pivot_idx:
                return nums[k_smallest]
            elif k_smallest < pivot_idx:
                return select(left, pivot_idx-1, k_smallest)
            else:
                return select(pivot_idx+1, right, k_smallest)

        return select(0, len(nums)-1, len(nums)-k)
