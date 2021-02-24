# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        nums = []
        cur = head
        while cur:
            nums.append(cur.val)
            cur = cur.next
        if len(nums) == 0: return None
        nums.sort()

        new_head = ListNode(nums[0])
        prev = new_head
        for num in nums[1:]:
            cur = ListNode(num)
            prev.next = cur
            prev = cur
        return new_head
