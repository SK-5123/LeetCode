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
    ListNode* reverseKGroup(ListNode* head, int k) {
         if (!head || k == 1)
            return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        
        int len = 0;
        ListNode* curr = head;
        while (curr) {
            len++;
            curr = curr->next;
        }
          while (len >= k) {
            curr = prev->next;
            ListNode* next_group = curr->next;
            for (int i = 1; i < k; i++) {
                curr->next = next_group->next;
                next_group->next = prev->next;
                prev->next = next_group;
                next_group = curr->next;
            }
            prev = curr;
            len -= k;
        }
        
return dummy->next;

    }
};