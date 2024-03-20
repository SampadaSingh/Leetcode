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
        ListNode* curr = list1;
        ListNode* prev_a = nullptr;
        ListNode* next_b = nullptr;

        // Traverse list1 to find the nodes at positions a and b
        for (int i = 0; i < b; i++) {
            if (i == a - 1)
                prev_a = curr;
            curr = curr->next;
        }
        next_b = curr->next;

        // Connect the last node of list2 to next_b
        ListNode* tail_list2 = list2;
        while (tail_list2->next)
            tail_list2 = tail_list2->next;
        tail_list2->next = next_b;

        // Connect prev_a to list2
        prev_a->next = list2;

        return list1;
    }
};