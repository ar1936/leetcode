// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int x) : val(x), next(NULL) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//     //     unordered_set<ListNode*>s;
//     //     if(headA==NULL||headB==NULL)
//     //         return NULL;
//     //     while(headA!=NULL)
//     //     {
//     //       m  s.insert(headA);
//     //         headA=headA->next;
//     //     }
//     //     while(headB!=NULL)
//     //     {
//     //         if(s.find(headB)!=s.end())
//     //             return headB;
//     //         headB=headB->next;
//     //     }
//     //     return NULL;
//     // }
        
        
        
//         // ListNode *pA = headA;
//         // ListNode *pB = headB;
//         // while (pA != pB) {
//         //     pA=pA == nullptr ? headB : pA->next;
//         //     pB=pB == nullptr ? headA : pB->next;
//         //     // if(pA)
//         // }
//         // return pA;
    
        
  
//     ListNode *p1 = headA;
//     ListNode *p2 = headB;
        
//     if (p1 == NULL || p2 == NULL) return NULL;

//     while (p1 != NULL && p2 != NULL && p1 != p2) {
//         p1 = p1->next;
//         p2 = p2->next;

//         //
//         // Any time they collide or reach end together without colliding 
//         // then return any one of the pointers.
//         //
//         if (p1 == p2) return p1;

//         //
//         // If one of them reaches the end earlier then reuse it 
//         // by moving it to the beginning of other list.
//         // Once both of them go through reassigning, 
//         // they will be equidistant from the collision point.
//         //
//         if (p1 == NULL) p1 = headB;
//         if (p2 == NULL) p2 = headA;
//     }
        
//     return p1;

//     }
        
// };




class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*>s;
        while(headA){
            s.insert(headA);
            headA=headA->next;
        }
        while(headB){
            if(s.find(headB)!=s.end())
                return headB;
            headB=headB->next;
        }
        return NULL;
        
    }
        
};

