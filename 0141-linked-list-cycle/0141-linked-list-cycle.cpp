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
    bool hasCycle(ListNode *head) {
        while(head==NULL){
            return false;
        }
        unordered_set<ListNode*>visited;
        while(head!=NULL){
            visited.insert(head);
            head=head->next;
            if(visited.count(head)){
                return true;
            }
        }
        return false;
    }
};