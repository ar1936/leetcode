/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // ListNode *detectCycle(ListNode *head) {
    //     unordered_set<ListNode*>st;
    //     while(head!=NULL){
    //         if(st.find(head)!=st.end())
    //             return head;
    //         st.insert(head);
    //         head=head->next;
    //     }
    //     return NULL;
    // }
    
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL)
            return NULL;
        ListNode *fast=head,*slow=head;
        while( fast->next!=NULL  && fast->next->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
                break;
        }
        if(fast!=slow)
            return NULL;
        slow=head;
        while(fast!=slow){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};