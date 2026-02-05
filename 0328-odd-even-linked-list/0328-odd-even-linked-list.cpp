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
    ListNode* oddEvenList(ListNode* head) {
      if(head == NULL || head->next== NULL){
        return head;
      }
      ListNode* firstNode = head;
      ListNode* secondNode = head->next;
      ListNode* startingOfSecondNode = secondNode;

      while(secondNode!= NULL && secondNode->next!=NULL){
        firstNode->next = secondNode->next;
        // firstNode = secondNode->next;
        firstNode = firstNode->next;

        secondNode->next = firstNode->next;
        // secondNode = firstNode->next;
        secondNode = secondNode->next;
      }
      

      firstNode->next =startingOfSecondNode;
      return head;

        
    }
};