# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        bit_str = ""
        cur = head
        while cur:
            bit_str += str(cur.val)
            cur = cur.next
        return int('0b'+bit_str, 2)
