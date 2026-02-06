#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q1, q2;

    MyStack() {}

    void push(int x) {
        q1.push(x);
    }

    int pop() {
        // Leave only last element in q1
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int topElement = q1.front();
        q1.pop();

        // Move everything back to q1
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }

        return topElement;
    }

    int top() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int topElement = q1.front();
        q2.push(topElement);  // keep it since top() shouldn't remove it
        q1.pop();

        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }

        return topElement;
    }

    bool empty() {
        return (q1.empty() && q2.empty());
    }
};


/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */