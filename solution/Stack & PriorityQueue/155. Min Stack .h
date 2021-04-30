#include "../global.h"
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        st.push(x);
        mt_set.insert(x);
    }

    void pop() {
        mt_set.erase(mt_set.find(st.top()));
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return *mt_set.begin();
    }

private:
    stack<int> st;
    multiset<int> mt_set;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */