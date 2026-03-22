struct Node {
    int val;
    int sub_min;
    Node *next;

    Node(int _val, int _sub_min, Node *_next)
        : val(_val), sub_min(_sub_min), next(_next) {}
};

class MinStack {
    Node *top_node = nullptr;

  public:
    MinStack() {}

    void push(int val) {
        int sub_min = !top_node                 ? val
                      : val < top_node->sub_min ? sub_min = val
                                                : sub_min = top_node->sub_min;
        top_node = new Node(val, sub_min, top_node);
    }

    void pop() {
        Node *victim = top_node;
        top_node = top_node->next;
        delete victim;
    }

    int top() {
        return top_node->val;
    }

    int getMin() {
        return top_node->sub_min;
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
