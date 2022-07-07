/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    private ListNode reverse(ListNode node){
        ListNode prev=null;
        while(node != null){
            ListNode tmp = node.next;
            node.next=prev;
            prev=node;
            node=tmp;
        }
        return prev;
    }
    public boolean isPalindrome(ListNode head) {
        ListNode fast=head, slow = head;
        while(fast!=null && fast.next!=null){
            fast=fast.next.next;
            slow=slow.next;
        }
        if(fast!=null){
            slow=slow.next;
        }
        slow=reverse(slow);
        fast=head;
        while(slow!=null){
            if(slow.val!=fast.val)
                return false;
            slow=slow.next;
            fast=fast.next;
        }
        return true;
    }
}