"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""
class Solution:
    def maxDepth(self, root: 'Node') -> int:
        if root is None: return 0
        stack = []
        stack.append((1,root))
        depth = 0
        while stack:
            current_depth, root = stack.pop()
            if root is None: continue
            depth = max(depth, current_depth)
            for c in root.children:
                stack.append((current_depth+1, c))
        return depth
