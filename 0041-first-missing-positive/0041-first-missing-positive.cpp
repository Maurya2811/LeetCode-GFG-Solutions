class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        int n = arr.size();
       
       for(int i=0;i<n;i++){
           if(arr[i]<=0 || arr[i]>n){
                continue;
           }
          
           if(arr[arr[i]-1]!=arr[i]){
               swap(arr[arr[i]-1],arr[i]);
               i--;
           }
           
       }
       
        for(int i=0;i<n;i++){
            if(arr[i]!=i+1){
                return i+1;
            }
        }
       return n+1;
    }
};