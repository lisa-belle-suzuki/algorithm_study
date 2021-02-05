# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        queue = deque()
        queue.append([root])
        p_record = None
        q_record = None
        isPFound = False
        isQFound = False
        while queue and not(isPFound and isQFound):
            history = queue.popleft()
            cur = history[-1]
            if cur is None:
                continue
            if cur == p:
                p_record = history
                isPFound = True
            elif cur == q:
                q_record = history
                isQFound = True
            left = cur.left
            right = cur.right
            queue.append(history + [left])
            queue.append(history + [right])

        for i in range(min(len(p_record), len(q_record))):
            if p_record[i] != q_record[i]:
                return p_record[i-1]
        return p_record[min(len(p_record), len(q_record))-1]
