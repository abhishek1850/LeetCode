/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {

public:
    Node* flatten(Node* head) {

        if (head == NULL) {
            return NULL;
        }

        Node* curr = head;

        while (curr != NULL) {
            if (curr->child == NULL) {
                curr = curr->next;
                continue;
            }
            Node* child = curr->child;
            Node* n = curr->next;

            curr->next = flatten(child);
            curr->next->prev = curr;
            curr->child = NULL;
            while (curr->next != NULL)
                curr = curr->next;

            if (n != NULL) {

                curr->next = n;
                n->prev = curr;
            }
        }
        return head;
    }
};