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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *slow=list1,*fast=list1,*temp=list2;
        a--;
        while(a--){
            slow=slow->next;
        }
        b+=1;
        while(b--){
            fast=fast->next;
        }
        slow->next=temp;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=fast;
        return list1;
    }
};