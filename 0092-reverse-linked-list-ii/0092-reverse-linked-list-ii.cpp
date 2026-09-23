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
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        if (head == NULL || head->next == NULL || l == r) {
            return head;
        }
        ListNode* left = head;
        ListNode* right = head;
        ListNode* lprev = NULL;

        for (int i = 1; i < l; i++) {
            lprev = left;
            left = left->next;
        }

        for (int i = 1; i < r; i++) {
            right = right->next;
        }
        ListNode* rnext = right->next;

        ListNode* revTail = left;

        ListNode* prev = NULL;

        for (int i = 0; i <= r - l; i++) {
            ListNode* next = left->next;
            left->next = prev;

            prev = left;
            left = next;
        }
        if (lprev != NULL) {
            lprev->next = prev;
        } else {
            head = prev;
        }

        revTail->next = rnext;

        return head;
    }
};