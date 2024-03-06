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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* current = head;

        while (current) {
            bool isDuplicate = false;

            while (current->next && current->val == current->next->val) {
                isDuplicate = true;
                ListNode* temp = current;
                current = current->next;
                delete temp;
            }

            if (isDuplicate) {
                ListNode* temp = current;
                current = current->next;
                delete temp;
                continue;
            }

            prev->next = current;
            prev = prev->next;
            current = current->next;
        }

        prev->next = nullptr;

        ListNode* result = dummy->next;
        delete dummy;

        return result;
    }
};
