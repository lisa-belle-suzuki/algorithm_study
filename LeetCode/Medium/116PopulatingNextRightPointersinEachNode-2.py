"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
from collections import deque
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if root is None: return None
        q = deque()
        q.append(root)
        while q:
            N = len(q)
            for i in range(N-1):
                node = q[i]
                # next pointerを設定
                node.next = q[i+1]
            # popして，left, rightを追加 (if not null)
            for i in range(N):
                parent = q.popleft()
                if parent.left is not None: q.append(parent.left)
                if parent.right is not None: q.append(parent.right)
        return root
