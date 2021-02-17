# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        if head is None: return None

        cur = head
        new_head = ListNode(head.val)
        new_cur = new_head
        while cur.next:
            if cur.next.val != val:
                new_cur.next = ListNode(cur.next.val)
                new_cur = new_cur.next
            cur = cur.next
        if new_head.val == val:
            return new_head.next
        return new_head
