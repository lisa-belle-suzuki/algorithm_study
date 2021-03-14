# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque


class Solution:
    def boundaryOfBinaryTree(self, root: TreeNode) -> List[int]:
        if not root.left and not root.right:
            return [root.val]
        left = []
        right = []
        leaves = []

        stack = [root.left]
        while stack:
            cur = stack.pop()
            if cur:
                left.append(cur.val)
                if cur.left:
                    stack.append(cur.left)
                elif cur.right:
                    stack.append(cur.right)

        stack = [root.right]
        while stack:
            cur = stack.pop()
            if cur:
                right.append(cur.val)
                if cur.right:
                    stack.append(cur.right)
                elif cur.left:
                    stack.append(cur.left)

        stack = []
        stack.append(root)
        while stack:
            cur = stack.pop()
            if cur.left:
                stack.append(cur.left)
                if cur.right:
                    stack.append(cur.right)
            else:
                if cur.right:
                    stack.append(cur.right)
                else:
                    leaves.append(cur.val)

        return [root.val] + left[:-1] + leaves[::-1] + right[:-1][::-1]
