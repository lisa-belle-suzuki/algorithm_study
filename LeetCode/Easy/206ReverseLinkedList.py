# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head is None:
            return None
        cur1 = head
        cur2 = ListNode(val=cur1.val)

        while cur1 is not None:
            # next2_を作る
            next1 = cur1.next
            if next1 is None:
                return cur2
            else:
                next2 = ListNode(val = next1.val)

            next2.next = cur2

            # 進める
            cur2 = next2
            cur1 = next1

        print("error")
        return None
