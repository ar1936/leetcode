# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head
        first_node = head
        second_node = head.next
        first_node.next = self.swapPairs(second_node.next)
        second_node.next = first_node
        return second_node