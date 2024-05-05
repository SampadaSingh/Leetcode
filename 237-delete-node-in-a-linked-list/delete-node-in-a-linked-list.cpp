/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node->next != nullptr) {
            ListNode* nextNode = node->next;
            node->val = nextNode->val; //copy value
            node->next = nextNode->next; // skip node
            delete nextNode;
        } else {
            delete node; //if node to be deleted is last node
        }
    }
};