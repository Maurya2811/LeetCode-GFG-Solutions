class MinStack {
    vector<pair<int,int>>st;
public:
    MinStack() {
        // vector<pair<int,int>>st;
    }
    
    void push(int val) {
        if(st.empty()){
            st.push_back({val,val});
        }else{
            pair<int,int>p={val,min(st.back().second,val)};
            st.push_back(p);
        }
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.back().first;
    }
    
    int getMin() {
       return st.back().second;
    }
};

