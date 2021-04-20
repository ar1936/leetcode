class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        unordered_set<ListNode *> s;
            
          while(head!=NULL)
          {
                  if(s.find(head)==s.end())
                      s.insert(head);  
                    else  
                      return true;

              head=head->next;
          }
          return false;  
        
    //     if(head==NULL)
    //         return false;
    //     ListNode *slow=head,*fast=head->next;
    //     while(slow!=fast)
    //     {
    //         if(fast==NULL||fast->next==NULL)
    //             return false;
    //         fast=fast->next->next;
    //         slow=slow->next;
    //     }
    //     return true;
    }
};