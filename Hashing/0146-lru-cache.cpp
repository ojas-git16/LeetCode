class LRUCache {
public:
    struct Node {
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int key1, int val1) {
            key = key1;
            val = val1;
            next = nullptr;
            prev = nullptr;
        }
    };
    int cap;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> mpp;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            int ans = mpp[key]->val;
            Node * nodeptr = mpp[key];
            Node * bef = nodeptr->prev;
            Node * aft = nodeptr->next;
            bef->next = aft;
            aft->prev = bef;
            bef = head;
            aft = head->next;
            nodeptr->next = aft;
            nodeptr->prev = head;
            bef->next = nodeptr;
            aft->prev = nodeptr;
            return ans;
        }
        return -1;
    }
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node * nodeptr = mpp[key];
            Node * bef = nodeptr->prev;
            Node * aft = nodeptr->next;
            nodeptr->next = nullptr;
            nodeptr->prev = nullptr;
            delete nodeptr;
            bef->next = aft;
            aft->prev = bef;
        }
        else if(mpp.size()==cap){
            Node * nodeptr = tail->prev;
            Node * bef = nodeptr->prev;
            Node * aft = nodeptr->next;
            nodeptr->next = nullptr;
            nodeptr->prev = nullptr;
            mpp.erase(nodeptr->key);
            delete nodeptr;
            bef->next = aft;
            aft->prev = bef;
        }
        Node* ptr = head->next;
        Node* newnode = new Node(key, value);
        ptr->prev = newnode;
        newnode->next = ptr;
        head->next = newnode;
        newnode->prev = head;
        mpp[key]=newnode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */