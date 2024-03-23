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
    // reverse list
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while (head != NULL) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        head = prev;
        return head;
    }

    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reversing the second half
        ListNode* second = reverse(slow->next);
        slow->next = NULL;
        ListNode* first = head;

        while (second) {
            // merge lists
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
    }
};