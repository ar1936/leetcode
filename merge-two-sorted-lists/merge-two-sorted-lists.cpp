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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        ListNode *ans=NULL;
        ListNode *dumb=NULL;
        while(l1!=NULL&l2!=NULL)
        {
            
            if(l1->val<l2->val)
            {
                if(ans==NULL)
                {
                    ans=l1;
                    l1=l1->next;
                    ans->next=NULL;
                    dumb=ans;

                }
                else 
                {
                    dumb->next=l1;
                    l1=l1->next;
                    dumb=dumb->next;
                    dumb->next=NULL;
                }
            }
            
            else
            {
                if(ans==NULL)
                {
                    ans=l2;
                    l2=l2->next;
                    ans->next=NULL;
                    dumb=ans;

                }
                else 
                {
                    dumb->next=l2;
                    l2=l2->next;
                    dumb=dumb->next;
                    dumb->next=NULL;
                }
            
            
        }
        
        }
        if(l1==NULL)
            {
                dumb->next=l2;
                return ans;
                
            }
            
        
        dumb->next=l1;
            return ans;
        
    }
};