# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def isPairSymmetric(left: TreeNode, right: TreeNode) -> bool:
    if left is None and right is None:
        return True
    if (left is None) != (right is None):
        return False
    if left.val != right.val:
        return False
    return isPairSymmetric(left.left, right.right) and isPairSymmetric(left.right, right.left)


class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if root is None:
            return True
        return isPairSymmetric(root.left, root.right)
