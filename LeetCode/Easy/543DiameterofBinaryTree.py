# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        max_d = 0

        def search(node):
            nonlocal max_d
            if node is None:
                return [0, 0]

            if node.left:
                left = max(search(node.left)) + 1
            else:
                left = 0

            if node.right:
                right = max(search(node.right)) + 1
            else:
                right = 0
            max_d = max(max_d, left + right)
            return [left, right]

        search(root)

        return max_d
