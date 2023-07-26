class StockSpanner {
public:
    
    
    
    // vector<int> ans;
    // stack<int,int>st;
    vector<int>arr;
    
    int NearestGreaterToLeft(int price){
        int size = arr.size();
        int i = size -2;
     if(size==1)
         return 1;
        while(i>=0 && arr[i]<=price ){
             i--;
        }
        if(size>=2)
        { 
        if(i<0 && arr[size-1]<arr[size-2]){
            return 1;
        }}
        return size -1-i;
    }
    StockSpanner() {
        
    }
    
    int next(int price) {
         arr.push_back(price);
      return   NearestGreaterToLeft( price);
       
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */