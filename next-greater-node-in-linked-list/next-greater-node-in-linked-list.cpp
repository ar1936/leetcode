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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>v,v1;
        while(head){
            v.push_back(head->val);
            head=head->next;
        }
        stack<int>s;
        for(int i=v.size()-1;i>=0;i--){
            if(s.empty())
                v1.push_back(0);
            else if(!s.empty()&&v[i]<s.top())
                v1.push_back(s.top());
            else if(!s.empty()&&v[i]>=s.top()){
                while(!s.empty()&&v[i]>=s.top())
                    s.pop();
                if(s.empty())
                    v1.push_back(0);
                else
                    v1.push_back(s.top());
            }
            s.push(v[i]);
        }
        reverse(v1.begin(),v1.end());
        return v1;
        
    }
};