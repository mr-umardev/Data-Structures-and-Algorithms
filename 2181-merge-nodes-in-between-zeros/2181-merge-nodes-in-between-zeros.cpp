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
    ListNode* mergeNodes(ListNode* head) {
   ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    int currentSum = 0;
    bool collecting = false;

    while (head != nullptr) {
        if (head->val == 0) {
            if (collecting) {
                current->next = new ListNode(currentSum);
                current = current->next;
                currentSum = 0;
            }
            collecting = true;
        } else {
            if (collecting) {
                currentSum += head->val;
            }
        }
        head = head->next;
    }

    ListNode* result = dummy->next;
    delete dummy; // Free the dummy node
    return result;
    }
};