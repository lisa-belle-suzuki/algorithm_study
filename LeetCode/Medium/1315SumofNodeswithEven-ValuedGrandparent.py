from collections import deque
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def sumEvenGrandparent(self, root: TreeNode) -> int:
        visited = []
        stack = [(root, visited)]
        ans = 0
        while stack:
            cur, v = stack.pop()
            if cur is None:
                continue
            if len(v) >= 2:
                g = v[-2]
                if g % 2 == 0:
                    ans += cur.val
            stack.append((cur.left, v + [cur.val]))
            stack.append((cur.right, v + [cur.val]))
        return ans
