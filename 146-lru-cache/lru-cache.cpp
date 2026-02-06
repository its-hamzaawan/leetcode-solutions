class LRUCache {
public:
    class Node {
    public:
        int key, val;
        Node* prev;
        Node* next;
        Node(int k, int v) {
            key = k;
            val = v;
            prev = next = NULL;
        }
    };

    Node* head;
    Node* tail;
    unordered_map<int, Node*> mp;
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];
        int ans = node->val;

        delNode(node);
        insertNode(node);

        return ans;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* oldNode = mp[key];
            delNode(oldNode);
            mp.erase(key);
            delete oldNode;
        }

        if (mp.size() == cap) {
           mp.erase(tail->prev->key);
           delNode(tail->prev);
        }

        Node* node = new Node(key, value);
        insertNode(node);
        mp[key] = node;
    }

    void insertNode(Node* node) {
        Node* nextNode = head->next;
        head->next = node;
        node->prev = head;
        node->next = nextNode;
        nextNode->prev = node;
    }

    void delNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */