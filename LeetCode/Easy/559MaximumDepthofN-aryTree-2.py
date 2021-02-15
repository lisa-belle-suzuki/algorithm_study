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
        max_depth = 1
        def search(node, depth):
            if node is None: return
            nonlocal max_depth
            if depth > max_depth: max_depth = depth
            for child in node.children:
                search(child, depth+1)
            return

        search(root, 1)
        return max_depth
