# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque


class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        # 全探索して，各高さで一番右のやつを使う
        height_map = defaultdict(list)

        def search(h, node):
            if node is None:
                return
            height_map[h].append(node.val)
            search(h + 1, node.left)
            search(h + 1, node.right)
            return

        search(0, root)
        ans = []
        for i in range(len(height_map)):
            ans.append(height_map[i][-1])
        return ans
