# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        idx_to_node = []
        cur = head
        while cur:
            idx_to_node.append(cur)
            cur = cur.next

        if len(idx_to_node) == 1: return None

        if n == len(idx_to_node):
            return head.next
        if n == 1:
            print("n=1")
            last = idx_to_node[-2]
            last.next = None
            return head

        prev = idx_to_node[-n-1]
        cur = idx_to_node[-n]
        next_ = idx_to_node[-n+1]
        prev.next = next_
        return head
