# Definition for Node.
# class Node:
#     def __init__(self, val=0, left=None, right=None, random=None):
#         self.val = val
#         self.left = left
#         self.right = right
#         self.random = random
from collections import deque


class Solution:
    def copyRandomBinaryTree(self, root: 'Node') -> 'NodeCopy':
        if root is None:
            return None
        new_root = NodeCopy(root.val)
        q = deque()
        q.append((root, new_root))
        org2new = {}
        while q:
            cur, new_cur = q.popleft()
            if cur is None:
                continue
            new_cur.val = cur.val
            org2new[cur] = new_cur
            l = Node()
            r = Node()
            if cur.left:
                new_cur.left = l
                q.append((cur.left, new_cur.left))
            if cur.right:
                new_cur.right = r
                q.append((cur.right, new_cur.right))

        q = deque()
        q.append((root, new_root))
        while q:
            cur, new_cur = q.popleft()
            if cur is None:
                continue
            if cur.random:
                new_cur.random = org2new[cur.random]
            q.append((cur.left, new_cur.left))
            q.append((cur.right, new_cur.right))

        return new_root
