# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:

        def is_same_tree(P,Q):
            while P and Q:
                if P.val!=Q.val:
                    return False
                return is_same_tree(P.left, Q.left) and is_same_tree(P.right, Q.right)
            if not (P is None and Q is None):
                return False
            return True

        return is_same_tree(p, q)
