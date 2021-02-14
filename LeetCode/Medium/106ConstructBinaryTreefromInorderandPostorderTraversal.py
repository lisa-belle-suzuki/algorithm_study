# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        def build(in_left, in_right):
            if in_left>in_right: return None
            root_val = postorder.pop()
            root_idx = idx_map[root_val]
            root = TreeNode(root_val)
            root.right = build(root_idx+1, in_right)
            root.left = build(in_left, root_idx-1)
            return root

        idx_map = {v:i for i,v in enumerate(inorder)}
        return build(0, len(inorder)-1)
