/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    int get_size(ListNode *head){
        int size=0;
        while(head){
            size++;
            head=head->next;
        }
        return size;
    }
public:
    ListNode* removeNthFromEnd1(ListNode* head, int n) {
        int size=get_size(head);
        if(size==1&&n==1)
            return NULL;
        ListNode *temp=head;
        if(size==n){
            temp=temp->next;
            return temp;
        }
        for(int i=0;i<size-n-1;i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;
    }
    
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow = head;
        for (int i = 0; i < n; i++) 
            fast = fast->next;
        if (!fast) 
            return head->next;
        while (fast->next) 
            fast = fast->next, slow = slow->next;
        slow->next = slow->next->next;
        return head;
    }

};