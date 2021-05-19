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
public:
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0), *tail = head;
        int sum=0,last_digits=0;
        while((l1!=NULL)&&(l2!=NULL)){
            sum+=(l1->val+l2->val);
            last_digits=sum%10;
            sum=sum/10;
            l1=l1->next;
            l2=l2->next;
            tail->next = new ListNode(last_digits);
            tail = tail->next;
        }
        while(l1!=NULL){
            sum+=(l1->val);
            last_digits=sum%10;
            sum=sum/10;
            l1=l1->next;
            tail->next = new ListNode(last_digits);
            tail = tail->next;
        }
         while(l2!=NULL){
            sum+=(l2->val);
            last_digits=sum%10;
            sum=sum/10;
            l2=l2->next;
            tail->next = new ListNode(last_digits);
            tail = tail->next;
        }
        if(sum!=0)
        {
            tail->next = new ListNode(sum);
            tail = tail->next;
        }
        return head->next ;
    }
};