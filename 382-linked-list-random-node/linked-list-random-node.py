# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def __init__(self, head: Optional[ListNode]):
        self.head = head
        self.n = 0
        node = head 
        while node:
            self.n+=1
            node = node.next


    def getRandom(self) -> int:
        random_ind = random.random()*self.n
        node = self.head 
        while random_ind>1:
            node = node.next 
            random_ind-=1
        return node.val


# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()