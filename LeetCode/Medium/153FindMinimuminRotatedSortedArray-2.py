from collections import deque
class Solution:
    def findMin(self, nums: List[int]) -> int:
        min_num = None
        def search(l, r):
            nonlocal min_num
            q = deque()
            q.append((l,r))
            while q:
                L,R = q.popleft()
                if L >= R: continue
                if L < 0 or R >= len(nums): continue
                if L+1==R:
                    if nums[L] > nums[R]:
                        min_num = nums[R]
                        break
                    continue
                C = (L+R)//2
                q.append((L, C))
                q.append((C, R))
            return

        search(0, len(nums)-1)
        print("min_num=", min_num)
        if min_num is None: return nums[0]
        else: return min_num
