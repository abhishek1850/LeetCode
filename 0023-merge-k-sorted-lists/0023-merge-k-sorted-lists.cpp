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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        for(int i =0;i<lists.size();i++){
          if(lists[i]){
          pq.push({lists[i]->val,lists[i]});
        }}


        while(!pq.empty()){
          auto pair = pq.top();
          pq.pop();
          if(pair.second->next){
            pq.push({pair.second->next->val,pair.second->next});
          }
          temp->next = pair.second;
          temp=temp->next;
        }
        return dummyNode->next;
    }
};