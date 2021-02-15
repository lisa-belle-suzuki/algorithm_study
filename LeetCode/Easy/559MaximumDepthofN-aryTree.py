"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""
from collections import deque
class Solution:
    def maxDepth(self, root: 'Node') -> int:
        if root is None: return 0
        max_depth = 1
        q = deque()
        q.append((root,1))
        while q:
            cur,depth = q.popleft()
            if cur is None: continue
            if depth > max_depth: max_depth = depth
            for child in cur.children:
                q.append((child,depth+1))
        return max_depth
