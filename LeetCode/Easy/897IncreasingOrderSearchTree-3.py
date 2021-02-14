# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def __init__(self):
        self.all_numbers = []
    def increasingBST(self, root: TreeNode) -> TreeNode:
        def traverse():
            q = deque([root])
            while q:
                cur = q.popleft()
                if cur is None: continue
                self.all_numbers.append(cur.val)
                if cur.left: q.append(cur.left)
                if cur.right: q.append(cur.right)
            return

        traverse()
        self.all_numbers.sort(reverse=True)
        print(self.all_numbers)
        new_root = TreeNode(self.all_numbers.pop())
        prev = new_root
        while len(self.all_numbers)>0:
            cur = TreeNode(self.all_numbers.pop())
            prev.right = cur
            prev = cur
        return new_root
