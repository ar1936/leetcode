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
    void solve(ListNode* l1, ListNode* l2, ListNode* tmp, int rem){
        if(l1==NULL && l2==NULL){
            if(rem!=0){
                ListNode *node = new ListNode(rem);
                tmp ->next = node;
                tmp = tmp ->next;
            }
            return ;
        }
        int sum=0,x=0,y=0;
        if(l1!=NULL){
            x=l1->val;
        }
        if(l2!=NULL){
            y=l2->val;
        }
        sum=x+y+rem;
        rem=sum/10;
        sum=sum%10;
        ListNode *node = new ListNode(sum);
        tmp ->next = node;
        tmp = tmp ->next;
        solve(l1==NULL?l1:l1->next,l2==NULL?l2:l2->next,tmp,rem);
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * ans = new ListNode(0);
        ListNode * tmp = ans;
        solve(l1,l2,tmp,0);
        
        return ans->next;
    }
};