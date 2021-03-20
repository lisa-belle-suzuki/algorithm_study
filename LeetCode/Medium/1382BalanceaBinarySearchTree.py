from collections import deque
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        numbers = []
        stack = [root]
        while stack:
            cur = stack.pop()
            if cur is None:
                continue
            numbers.append(cur.val)
            stack.append(cur.left)
            stack.append(cur.right)
        numbers.sort()
        print(numbers)

        q = deque()
        center = len(numbers)//2
        root = TreeNode(numbers[center])
        if 0 <= center-1:
            left = TreeNode()
            root.left = left
            q.append((left, 0, center-1))
        if center+1 <= len(numbers)-1:
            right = TreeNode()
            root.right = right
            q.append((right, center+1, len(numbers)-1))

        while q:
            cur_node, l, r = q.popleft()
            if l < 0 or r >= len(numbers) or l > r:
                continue
            center = (l+r)//2
            cur_node.val = numbers[center]
            if l <= (center-1):
                left = TreeNode()
                cur_node.left = left
                q.append((left, l, center-1))
            if center+1 <= r:
                right = TreeNode()
                cur_node.right = right
                q.append((right, center+1, r))

        return root
