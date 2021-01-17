# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if head is None or head.next is None:
            return False

        fast = head.next.next
        slow = head.next
        while fast is not None and slow is not None:
            if hex(id(slow))==hex(id(fast)):
                return True
            if fast.next is not None:
                fast = fast.next.next
            else:
                return False
            slow = slow.next
        return False
