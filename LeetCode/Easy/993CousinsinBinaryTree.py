# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        q = deque()
        q.append((root, 0))
        isXFound = False
        isYFound = False
        x_parent = None
        y_parent = None
        x_depth = None
        y_depth = None
        while q:
            if isXFound and isYFound: break
            cur = q.popleft()
            node, depth = cur
            if node.left is not None:
                if node.left.val == x:
                    x_depth = depth + 1
                    x_parent = id(node)
                    isXFound = True
                elif node.left.val == y:
                    y_depth = depth + 1
                    y_parent = id(node)
                    isYFound = True
                q.append((node.left, depth+1))
            if node.right is not None:
                if node.right.val == x:
                    x_depth = depth + 1
                    x_parent = id(node)
                    isXFound = True
                elif node.right.val == y:
                    y_depth = depth + 1
                    y_parent = id(node)
                    isYFound = True
                q.append((node.right, depth+1))
        if x_depth == y_depth and x_parent != y_parent: return True
        return False
