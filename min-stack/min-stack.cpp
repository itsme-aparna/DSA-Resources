class Node {
public:
    Node *next;
    int val;
    int min;
    
    Node (int _val, int _min) {
        next = NULL;
        val = _val;
        min = _min;
    }
};

class MinStack {
private:
    Node *list;
public:
    MinStack() {
        list = NULL;
    }
    
    void push(int val) {
        Node *n ;
        if (list == NULL) {
            n = new Node(val, val);
        } else {
            n = new Node(val, min(val, list->min));
            n->next = list;
        }
        list = n;
    }
    
    void pop() {
        Node *temp = list;
        list = list->next;
        delete(temp);
    }
    
    int top() {
        return list->val;
    }
    
    int getMin() {
        return list->min;
    }
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */