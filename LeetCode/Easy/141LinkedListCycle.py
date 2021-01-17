# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if head is None or head.next is None:
            return False
        cur = head
        isVisited = {}
        isVisited[hex(id(cur))] = True

        cur = cur.next
        while cur is not None:
            if hex(id(cur)) in isVisited:
                return True
            isVisited[hex(id(cur))] = True
            cur = cur.next

        return False
