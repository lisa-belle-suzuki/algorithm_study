# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        isAVisited = {}

        curA = headA
        while curA is not None:
            isAVisited[hex(id(curA))] = True
            curA = curA.next

        curB = headB
        while curB is not None:

            if hex(id(curB)) in isAVisited:
                return curB
            curB = curB.next

        return None
