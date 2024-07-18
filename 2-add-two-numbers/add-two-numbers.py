# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        ans = ListNode()
        dummy = ans
        sum = 0
        rem = 0
        while l1 or l2:
            if l1 and l2:
                sum = l1.val + l2.val + rem
                rem = sum//10
                l1 = l1.next
                l2 = l2.next
            elif l1:
                sum = l1.val + rem
                rem = sum//10
                l1 = l1.next
            elif l2:
                sum = l2.val + rem
                rem = sum//10
                l2 = l2.next
            
            node = ListNode(sum%10)
            dummy.next = node
            dummy = dummy.next

        if rem:
            node = ListNode(rem)
            dummy.next = node
            dummy = dummy.next

        return ans.next    