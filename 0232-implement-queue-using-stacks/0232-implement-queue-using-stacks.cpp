class MyQueue {
public:
    
//    Amortized O(1) ==> Most of the Operation is O(1) and very few time O(n);
    
    stack<int> input;
    stack<int> output;
    int peekEle ;
    MyQueue() {
        
    }
    
    void push(int x) {
       if(input.empty()){
           peekEle =x;
       }
           input.push(x);
    }
    
    int pop() {
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        int temp= output.top();
        output.pop();
        return temp;
    }
    
    int peek() {
        if(!output.empty()){
            return output.top();
        }
        return peekEle;
    }
    
    bool empty() {
        return input.empty() && output.empty();
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