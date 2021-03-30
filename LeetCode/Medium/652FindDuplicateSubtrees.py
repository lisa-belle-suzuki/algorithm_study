# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findDuplicateSubtrees(self, root: TreeNode) -> List[TreeNode]:
        cnt = defaultdict(int)
        ans = []

        def search(node):
            if not node:
                return "#"
            serial = "{},{},{}".format(
                node.val, search(node.left), search(node.right))
            cnt[serial] += 1
            if cnt[serial] == 2:
                ans.append(node)
            return serial
        search(root)
        return ans
