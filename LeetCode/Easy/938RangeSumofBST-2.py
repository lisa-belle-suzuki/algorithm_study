# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def __init__(self):
        self.ans = 0

    def rangeSumBST(self, root: TreeNode, low: int, high: int) -> int:
        q = deque()
        q.append(root)
        while q:
            cur = q.popleft()
            if cur is None: continue
            if low <= cur.val <= high: self.ans += cur.val
            q.append(cur.left)
            q.append(cur.right)
        return self.ans
