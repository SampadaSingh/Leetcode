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
class compare {
public:
    bool operator()(const ListNode* a, const ListNode* b) {
        return (a->val > b->val);
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(0); // dummy node
        ListNode* temp = head; // current position
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        // push the heads of all non-empty lists into the priority queue
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }
        while (!pq.empty()) {
            auto least = pq.top(); // extract ListNode with smallest value
            pq.pop();
            temp->next =least; // connect smallest ListNode from pq to merged list
            temp = temp->next; // move temp to new node
            if (least->next) {
                pq.push(least->next);
            }
        }
        return head->next;
    }
};