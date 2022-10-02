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
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
        ListNode * ans = new ListNode();
        ListNode * tmp = ans;
        int sum=0,rem=0;
        while(l1&&l2){
            sum=l1->val + l2->val + rem;
            rem = sum/10;
            sum=sum%10;
            ListNode * node = new ListNode(sum);
            tmp -> next = node;
            tmp = tmp -> next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            sum=l1->val + rem;
            rem = sum/10;
            sum=sum%10;
            ListNode * node = new ListNode(sum);
            tmp -> next = node;
            tmp = tmp -> next;
            l1 = l1->next;
        }
        
        
        while(l2){
            sum=l2->val + rem;
            rem = sum/10;
            sum=sum%10;
            ListNode * node = new ListNode(sum);
            tmp -> next = node;
            tmp = tmp -> next;
            l2 = l2->next;
        }
        if(rem){
            ListNode * node = new ListNode(rem);
            tmp -> next = node;
            tmp = tmp -> next;
        }
        return ans->next;
    }
};