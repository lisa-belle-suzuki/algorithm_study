# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        def dfs(node):
            if node is None: return []
            return dfs(node.left) + [node.val] + dfs(node.right)

        return dfs(root)
