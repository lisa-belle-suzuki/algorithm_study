# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        def build(cur_list):
            if len(cur_list)==0: return None
            root_idx = len(cur_list)//2
            root_node = TreeNode(cur_list[root_idx])
            root_node.left = build(cur_list[:root_idx])
            root_node.right = build(cur_list[root_idx+1:])
            return root_node

        num_list = []
        cur = head
        while cur:
            if cur is None: continue
            num_list.append(cur.val)
            cur = cur.next
        num_list.sort()
        return build(num_list)
