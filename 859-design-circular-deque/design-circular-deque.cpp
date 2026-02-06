class MyCircularDeque {
public:
   int front,rear,currSize,cap;
   deque<int>deque;
    MyCircularDeque(int k) {
        cap = k;
        deque.resize(k);
        front = 0;
        rear = k-1;
        currSize =0;

    }
    
    bool insertFront(int value) { // for insert at front,  move front back then insert
        if(isFull()) return false;
        front = (front -1 +cap)%cap; // front end
       deque[front]=value;   
       currSize++;   
        return true;
    }
    
    bool insertLast(int value) {  // rear end
        if(isFull()) return false;
        rear = (rear +1)%cap;
        deque[rear]=value;
        currSize++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        front = (front +1)%cap;
        currSize--;
        return true;
    }
    
    bool deleteLast() { //rear end
        if(isEmpty()) return false;
        rear = (rear-1+cap)%cap;
        currSize--;
        return true;
    }
    
    int getFront() {
        return isEmpty()?-1:deque[front];
    }
    
    int getRear() {
        return isEmpty()?-1:deque[rear];
    }
    
    bool isEmpty() {
        if(currSize==0) return true;
        else {
            return false;
        }
    }
    
    bool isFull() {
     if(currSize == cap) return true;
     else{
        return false;
     }     
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */