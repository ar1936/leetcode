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
    ListNode* sortList(ListNode* head) {
        if(head==NULL)
            return NULL;
        vector<int>ans;
        while(head!=NULL){
            ans.push_back(head->val);
            head=head->next;
        }
        sort(ans.begin(),ans.end());
        cout<<ans[0]<<"\n";
        ListNode *res=NULL,*curr=NULL;
        for(int i=0;i<ans.size();i++){
            ListNode *temp=new ListNode (ans[i]);
            if(res==NULL){
                res=temp;
                curr=res;
            }
            else{
                curr->next=temp;
                curr=curr->next;
            }
        }
        return res;
    }
};

//      ListNode* res=NULL;
//         curr=NULL;
        
//         for(int i=0;i<vec.size();i++)
//         {
//             ListNode* temp=new ListNode(vec[i]);
//             if(res==NULL)
//             {
//                 res=temp;
//                 curr=res;
//             }
//             else
//             {
//                 curr->next=temp;
//                 curr=curr->next;
//             }
//         }
        
//         return res;