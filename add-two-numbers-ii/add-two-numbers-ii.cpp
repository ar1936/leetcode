// My try->1;

// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     int size(ListNode *temp){
//         int count=0;
//         while(temp!=NULL){
//             count++;
//             temp=temp->next;
//         }
//         return count;
//     }
//     stack<int>s;
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode*head=new ListNode(0),*temp=head;
//         int sum=0,last_digits=0;
//         int size1=size(l1);
//         int size2=size(l2);
//         int m=abs(size1-size2);
//         if(size1>size2){
//             while(m--){
//                 int last_digits=l1->val;
//                 temp->next= new ListNode(last_digits);
//                 temp=temp->next;
//                 l1=l1->next;
                
//             }
//         }
//         else{
//             while(m--){
//                 int last_digits=l2->val;
//                 temp->next= new ListNode(last_digits);
//                 temp=temp->next;
//                 l2=l2->next;
//             }
//         }
//         m=abs(size1-size2);
//         size1=min(size1,size2);
//         while(size1--){
//             sum+=(l1->val)+(l2->val);
//             last_digits=sum%10;
//             s.push(last_digits);
//             // temp->next=new ListNode(last_digits);
//             // temp=temp->next;
//             sum=sum/10;
//             l1=l1->next;
//             l2=l2->next;
//         }
//         while(!s.empty()){
//             temp->next=new ListNode(s.top());
//             temp=temp->next;
//             s.pop();
//         }
    
//         return head->next;
//     }
// };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        
        int carry = 0, first, second;
        ListNode* head = NULL;
        while (!s1.empty() || !s2.empty() || carry) {
            if (!s1.empty()) {
                first = s1.top();
                s1.pop();
            }
            else
                first = 0;
            
            if (!s2.empty()) {
                second = s2.top();
                s2.pop();
            }
            else
                second = 0;
            
            int temp = first+second+carry;
            ListNode* node = new ListNode(temp%10);
            node->next = head;
            head = node;
            carry = temp/10;
            
        }
        return head;
    }
};