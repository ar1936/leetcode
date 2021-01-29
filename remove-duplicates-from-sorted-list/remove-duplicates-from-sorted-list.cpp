class Solution {
  public:
    ListNode * deleteDuplicates(ListNode * head) {
      if (head == NULL || head -> next == NULL) {
        return head;
      } else {
        ListNode * current;
        current = head;
        while (current -> next != NULL) {
          if (current -> val != current -> next -> val) {
            current = current -> next;
          } else {
            current -> next = current -> next -> next;
          }
        }
        return head;
      }
    }
};