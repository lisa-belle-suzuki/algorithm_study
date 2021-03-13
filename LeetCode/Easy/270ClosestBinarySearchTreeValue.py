# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def closestValue(self, root: TreeNode, target: float) -> int:
        closest = float('inf')
        stack = [root]
        while stack:
            cur = stack.pop()
            if cur is None:
                continue
            if abs(cur.val - target) < abs(closest - target):
                closest = cur.val
            stack.append(cur.left)
            stack.append(cur.right)

        return closest
