

class MyStack {
public:
    queue<int> que;
     // queue<int> temp;
    MyStack() {
        
    }
 // By using Two Queues
 /*   
    void push(int x) {
         temp.push(x);
                 
        while(!que.empty()){
            temp.push(que.front());
            que.pop();
        }
      while(!temp.empty()){
            que.push(temp.front());
            temp.pop();
        }
        
    }
 */
    
 // By using Onr Queue
    void push(int x){
        int n= que.size();
        que.push(x);
       while(n--){
           que.push(que.front());
           que.pop();
       }
    }
    
    int pop() {
        int top=que.front();
        que.pop();
        return top;
    }
    
    int top() {
        return que.front();
    }
    
    bool empty() {
        return que.empty();
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