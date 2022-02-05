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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        vector<int> v;
        ListNode *temp;
            
        for(auto &it: lists){
            temp = it;
            while(temp){
                v.push_back(temp->val);
                temp = temp->next;
            }
            
        }
        
        ListNode *ans = new ListNode(0);
        temp = ans;
        
        sort(v.begin(), v.end());
        int n = v.size(), i = 0;
        
        while(i < n){
            ans->next = new ListNode(v[i]);
            ans = ans->next;
            i++;
        }
        
        return temp->next;
        
    }
};