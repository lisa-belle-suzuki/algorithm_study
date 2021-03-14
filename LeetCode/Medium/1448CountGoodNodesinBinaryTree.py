# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        stack = [(root, -float('inf'))]
        count = 0
        while stack:
            node, max_val = stack.pop()
            if not node:
                continue
            if node.val >= max_val:
                count += 1
                max_val = node.val
            stack.append((node.left, max_val))
            stack.append((node.right, max_val))
        return count
