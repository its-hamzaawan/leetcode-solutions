
class BrowserHistory {
public:
struct ListNode {
    string val;
    ListNode* prev;
    ListNode* next;

    ListNode(string x) {
        val = x;
        prev = NULL;
        next = NULL;
    }
};

    ListNode* current;

    BrowserHistory(string homepage) {
        current = new ListNode(homepage);
    }
    
    void visit(string url) {
     

        ListNode* node = new ListNode(url);
        node->prev = current;
        current->next = node;
        current = node;
    }
    
    string back(int steps) {
        while (steps > 0 && current->prev != NULL) {
            current = current->prev;
            steps--;
        }
        return current->val;
    }
    
    string forward(int steps) {
        while (steps > 0 && current->next != NULL) {
            current = current->next;
            steps--;
        }
        return current->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */