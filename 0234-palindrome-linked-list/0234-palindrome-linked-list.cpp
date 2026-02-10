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

  ListNode* reverse(ListNode* head){
    ListNode* curr = head;
    ListNode* prev = NULL;
    while(curr!=NULL){
      ListNode* next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    head = prev;
    return head;
  }
public:
    bool isPalindrome(ListNode* head) {
      stack<int>st;
      ListNode* temp = head;
      while(temp!=NULL){
        st.push(temp->val);
        temp=temp->next;
      }

      temp = head;
      while(temp!=NULL){
        if(temp->val!=st.top()){
          return false;
        }
        temp = temp->next;
        st.pop();
      }
      return true;   
    // if(head==NULL || head->next==NULL){
    //   return true;
    // }
    // ListNode* slow = head;
    // ListNode* fast = head;
    // while(fast->next!=NULL && fast->next->next!=NULL){
    //   slow = slow->next;
    //   fast = fast->next->next;
    // }

    // ListNode* newNode = reverse(slow->next);

    // ListNode* first = head;
    // ListNode* second = newNode;

    // while(second!=NULL){
    //   if(first->val != second->val){
    //     reverse(newNode);
    //     return false;
    //   }
    //   first = first ->next;
    //   second = second ->next;
    // }
    // reverse(newNode);
    // return true;
    }
};