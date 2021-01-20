# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

def listNodeToNumber(node) -> int:
    tens = 1
    ans = 0
    cur = node
    while cur is not None:
        ans += cur.val * tens
        tens *= 10
        cur = cur.next
    return ans

def numberToListNode(num) -> ListNode:
    start = ListNode(num%10)
    num //= 10
    prev = start
    while num > 0:
        cur = ListNode(num%10)
        num //= 10
        prev.next = cur
        prev = cur
    return start


class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        return numberToListNode(listNodeToNumber(l1) + listNodeToNumber(l2))
