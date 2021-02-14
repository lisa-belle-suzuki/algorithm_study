# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getLonelyNodes(self, root: TreeNode) -> List[int]:
        ans = []

        def solve(cur):
            if cur is None:
                return
            if cur.left is None and not cur.right is None:
                ans.append(cur.right.val)
                solve(cur.right)
            elif cur.right is None and not cur.left is None:
                ans.append(cur.left.val)
                solve(cur.left)
            else:
                solve(cur.left)
                solve(cur.right)
            return

        solve(root)
        return ans
