class Node{
public:
    int key, data;
    Node* next;
    Node* prev;

    Node(int k,int v){
        key = k;
        data = v;
        next = prev = NULL;
    }
};

class LRUCache {
public:
    int cap;
    unordered_map<int,Node*>mp;
    Node* head;
    Node* tail;


    LRUCache(int capacity) {
         cap = capacity;
         head = new Node(-1,-1);
         tail = new Node(-1,-1);
         head->next = tail;
         tail->prev = head;
    }

    void addNode(Node* node){
         Node* temp = head->next;

         node->next = temp;
         node->prev = head;
        
         head->next = node;
         temp->prev = node;
         
    }

    void deleteNode(Node* node){
        Node* prev = node->prev;
        Node* next = node->next;

        prev->next = next;
        next->prev = prev;
        // delete node;  -> not use here !! find out reason..............
    }

    int get(int key) {
      if(mp.find(key)!=mp.end()){
        Node* temp = mp[key];
        int ans = temp->data;
        deleteNode(temp);
        addNode(temp);
        return ans;
      }

       return -1; 
    }

    void put(int key, int value) {

      if(mp.find(key)!=mp.end()){
         Node* temp = mp[key];
         deleteNode(temp);
         mp.erase(key);
      }

      if(mp.size()==cap){
        Node* temp = tail->prev;
        deleteNode(temp);
        
        mp.erase(temp->key);
        delete temp;
      }

      Node* newNode = new Node(key,value);
      addNode(newNode);
      mp[key]=newNode;  
    }
};