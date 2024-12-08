class LRUCache {
public:
    class Node{
        public:
        int key, val;
        Node *next, *prev;
        Node(int key, int val){
            this->key =  key;
            this->val = val;
        }
    };
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int cap;
    unordered_map<int, Node*> mp;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addNode(Node* newnode){
        Node* temp = head -> next;
        newnode -> next = temp;
        newnode -> prev = head;

        head -> next = newnode;
        temp -> prev = newnode;
    }
    void deleteNode(Node* delnode){
        Node* prevv = delnode -> prev;
        Node* nextt = delnode -> next;

        prevv -> next = nextt;
        nextt -> prev = prevv;
    }
    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* resNode = mp[key];
            int ans = resNode -> val;

            mp.erase(key);
            deleteNode(resNode);
            addNode(resNode);

            mp[key] = head -> next;
            return ans;
        }
        return -1;
    }
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* curr = mp[key];
            mp.erase(key);
            deleteNode(curr);
        }
        if(mp.size() == cap){
            mp.erase(tail -> prev -> key);
            deleteNode(tail -> prev);
        }
        addNode(new Node(key, value));
        mp[key] = head -> next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */