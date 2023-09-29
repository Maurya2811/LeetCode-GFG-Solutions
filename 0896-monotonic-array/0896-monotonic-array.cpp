class Solution {
public:
    bool isMonotonic(vector<int>& arr) {
          int n=arr.size();
        if(n<2)
            return true;
        
        bool increasing = false;
        bool decreasing = false;
        
        for(int i=0;i<n-1;i++){
            
            if(arr[i]<arr[i+1])
                increasing = true;
            if(arr[i]>arr[i+1]){
                decreasing = true;
            }
                
        }
        
        if(increasing && decreasing)
            return false;
        
        return true;
    }
};