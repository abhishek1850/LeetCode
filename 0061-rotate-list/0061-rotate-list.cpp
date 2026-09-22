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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }
        int n = 0;
        ListNode* curr = head;
        while (curr != NULL) {
            n++;
            curr = curr->next;
        }
        curr = head;
        k = k % n;
        if (k == 0) {
            return head;
        }
        int nn = n - k;
        for (int i = 1; i < nn; i++) {
            curr = curr->next;
        }

        ListNode* next = curr->next;
        curr->next = NULL;
        ListNode* tail = next;
        while (tail->next != NULL) {
            tail = tail->next;
        }

        tail->next = head;
        head = next;
        return head;
    }
};