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

                // using vector 
// class Solution {
// public:
//     ListNode* rotateRight1(ListNode* head, int k) {
//         if(head==NULL)
//             return NULL;
//         vector<int>v;
//         while(head!=NULL){
//             v.push_back(head->val);
//             head=head->next;
//         }
//         k=k%v.size();
//         vector<int>v1(v.size());
//         for(int i=k;i<v.size();i++){
//             v1[i]=v[i-k];
//         }
//         for(int i=0;i<k;i++){
//             v1[i]=v[v.size()-k+i];
//         }
//         ListNode *ans=new ListNode (v1[0]);
//         ListNode *temp=ans;
//         for(int i=1;i<v1.size();i++){
//             ListNode *node = new ListNode(v1[i]);
//             temp->next=node;
//             temp=temp->next;
//         }
//         return ans;
//     }
// };


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        
        int len=1; // number of nodes
        ListNode *newH, *tail;
        newH=tail=head;
        
        while(tail->next)  // get the number of nodes in the list
        {
            tail = tail->next;
            len++;
        }
        tail->next = head; // circle the link

        if(k %= len) 
        {
            for(auto i=0; i<len-k; i++) 
                tail = tail->next; // the tail node is the (len-k)-th node (1st node is head)
        }
        newH = tail->next; 
        tail->next = NULL;
        return newH;
    }
};