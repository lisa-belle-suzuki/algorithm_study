# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        def inorder(r):
            if not r: return []
            return inorder(r.left) + [r.val] + inorder(r.right)

        return inorder(root)[k-1]
