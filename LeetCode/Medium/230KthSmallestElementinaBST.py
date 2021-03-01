# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
import heapq
class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        nums = []
        stack = [root]
        while stack:
            cur = stack.pop()
            if cur is None: continue
            nums.append(cur.val)
            if cur.left: stack.append(cur.left)
            if cur.right: stack.append(cur.right)

        heapq.heapify(nums)
        for i in range(k-1):
            heapq.heappop(nums)
        return heapq.heappop(nums)
