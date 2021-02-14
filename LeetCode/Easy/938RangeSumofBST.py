# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def __init__(self):
        self.ans = 0

    def rangeSumBST(self, root: TreeNode, low: int, high: int) -> int:
        def solve(cur_node):
            if cur_node is None: return
            val = cur_node.val
            if low <= val <= high: self.ans += val
            solve(cur_node.left)
            solve(cur_node.right)
            return

        solve(root)
        return self.ans
