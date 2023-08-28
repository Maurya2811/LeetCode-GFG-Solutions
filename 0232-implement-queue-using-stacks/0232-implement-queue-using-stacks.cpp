class MyQueue {
public:
    
    // Stack 1 will do push Only
    // Stack 2 will do pop and peek operation
    
    stack<int> st1;    
    stack<int> st2;

    MyQueue() {
        
    }
    
    void push(int x) {
         while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        st1.push(x);
    }
    
    int pop() {
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        int temp = st2.top();
        st2.pop();
        return temp;
    }
    
    int peek() {
         while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
       return st2.top();
    }
    
    bool empty() {
        return st1.empty() && st2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */