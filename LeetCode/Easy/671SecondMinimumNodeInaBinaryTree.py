from collections import deque
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def findSecondMinimumValue(self, root: TreeNode) -> int:
        q = deque()
        q.append(root)
        first_min = root.val
        second_min = float('inf')
        while q:
            cur = q.popleft()
            if cur is None:
                continue
            if cur.val > first_min:
                second_min = min(second_min, cur.val)
            q.append(cur.left)
            q.append(cur.right)

        if second_min != float('inf'):
            return second_min
        return -1
