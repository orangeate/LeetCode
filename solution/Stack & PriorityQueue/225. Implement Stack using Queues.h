#include "../global.h"
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        if(_qu1.empty())
            _qu2.push(x);
        else
            _qu1.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(_qu1.empty())
        {
            while(_qu2.size() > 1)
            {
                _qu1.push(_qu2.front());
                _qu2.pop();
            }
            int val = _qu2.front();
            _qu2.pop();
            return val;
        }
        else
        {
            while(_qu1.size() > 1)
            {
                _qu2.push(_qu1.front());
                _qu1.pop();
            }
            int val = _qu1.front();
            _qu1.pop();
            return val;
        }
    }

    /** Get the top element. */
    int top() {
        if(_qu1.empty())
        {
            while(_qu2.size() > 1)
            {
                _qu1.push(_qu2.front());
                _qu2.pop();
            }
            int val = _qu2.front();
            _qu1.push(val);
            _qu2.pop();
            return val;
        }
        else
        {
            while(_qu1.size() > 1)
            {
                _qu2.push(_qu1.front());
                _qu1.pop();
            }
            int val = _qu1.front();
            _qu2.push(val);
            _qu1.pop();
            return val;
        }
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return _qu1.empty() && _qu2.empty();
    }

private:
    queue<int> _qu1;
    queue<int> _qu2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */