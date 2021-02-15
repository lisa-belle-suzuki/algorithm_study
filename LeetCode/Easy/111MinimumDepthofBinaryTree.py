# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if root is None: return 0
        q = deque()
        q.append((root,1))
        min_depth = 100000
        while q:
            node, depth = q.popleft()
            if node is None: continue
            if node.left is None and node.right is None:
                min_depth = min(min_depth, depth)
                return min_depth
            q.append((node.left, depth+1))
            q.append((node.right, depth+1))

        return min_depth
