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
    void solve(ListNode * tmp , int n){
        if(n==1)
        {
            tmp->next = tmp->next->next;
            return ;
        }
        solve(tmp->next,n-1);
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz=0;
        ListNode * tmp = head;
        while(tmp){
            sz++;
            tmp = tmp -> next;
        }
        if(sz==1)
            return NULL;
        if(sz==2){
            if(n==2){
                return head->next;
            }
            else{
                head->next=NULL;
                return head;
            }
        }
        if(sz==n){
            return head->next;
        }
        tmp = head;
        solve(tmp,sz-n);
        return head;
    }
};