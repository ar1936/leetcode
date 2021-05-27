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
    ListNode* swapNodes(ListNode* head, int k) {
        int listLength = 0;
        ListNode* currentNode = head;
        // find the length of linked list
        while (currentNode) {
            listLength++;
            currentNode = currentNode->next;
        }
        // set the front node at kth node
        ListNode* frontNode = head;
        for (int i = 1; i < k; i++) {
            frontNode = frontNode->next;
        }
        // set the end node at (listLength - k)th node
        ListNode* endNode = head;
        for (int i = 1; i <= listLength - k; i++) {
            endNode = endNode->next;
        }
        // swap the values of front node and end node
        swap(frontNode->val, endNode->val);
        return head;
    }
};