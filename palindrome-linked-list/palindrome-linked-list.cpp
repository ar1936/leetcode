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
    // bool solve(vector<int>v){
    //     if(v.size()==1)
    //         return true;
    //     for(int i=0;i<v.size()/2;i++){
    //         if(v[i]!=v[v.size()-i-1])
    //             return false;
    //     }
    //     return true;
    // }
    // bool isPalindrome(ListNode* head) {
    //     vector<int>v;
    //     while(head!=NULL){
    //         v.push_back(head->val);
    //         head=head->next;
    //     }
    //     return solve(v);
    // }
    

    bool isPalindrome(ListNode *head)
    {
        ListNode *slow = head, *fast = head, *prev = NULL, *tmp;
        while (fast && fast->next) // finding mid point
            fast = fast->next->next,
            tmp = slow->next, slow->next = prev, prev = slow, slow = tmp;
        slow = (fast ? slow->next : slow); // for odd length case as mentioned above
        while (slow)                       // check if linked lists starting at prev and slow are equal
            if (slow->val != prev->val)
                return false;
            else
                slow = slow->next, prev = prev->next;
        return true;
    }
};