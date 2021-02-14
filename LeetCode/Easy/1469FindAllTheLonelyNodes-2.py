# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque
class Solution:
    def getLonelyNodes(self, root: TreeNode) -> List[int]:
        q = deque()
        q.append(root)
        ans = []
        while q:
            cur = q.popleft()
            if cur is None:
                continue
            if cur.left and not cur.right:
                ans.append(cur.left.val)
            elif cur.right and not cur.left:
                ans.append(cur.right.val)
            q.append(cur.left)
            q.append(cur.right)
        return ans
