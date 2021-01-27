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
int get_size(ListNode* head)
{
    int count=0;
    while(head->next!=NULL)
    {
        head=head->next;
        count++;
    }
    return count;
}
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans(0);
        int i=get_size(head);
        while(head->next!=NULL)
        {
            ans+=(head->val)<<i;
            i--;
            head=head->next;
        }
         ans+=(head->val)<<i;
            i++;
        
        return ans;
    }
};