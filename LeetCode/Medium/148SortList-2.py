# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return head
        mid = self.getMid(head)
        left = self.sortList(head)
        right = self.sortList(mid)
        return self.merge(left, right)

    def merge(self, list1: ListNode, list2: ListNode):
        dummyHead = ListNode()
        tail = dummyHead
        while list1 and list2:
            if list1.val < list2.val:
                tail.next = list1
                list1 = list1.next
                tail = tail.next
            else:
                tail.next = list2
                list2 = list2.next
                tail = tail.next

        if list1:
            tail.next = list1
        else:
            tail.next = list2
        return dummyHead.next

    def getMid(self, node):
        midPrev = None
        while node and node.next:
            if midPrev is None:
                midPrev = node
            else:
                midPrev = midPrev.next
            node = node.next.next
        mid = midPrev.next
        midPrev.next = None
        return mid
