class Solution {
public:
    int trap(vector<int>& arr) {
        int n= arr.size();
          vector<int> left(n);
          vector<int> right(n);
          left[0] = arr[0];
          right[n-1] = arr[n-1];
         
         for(int i=1;i<n;i++){
              left[i]= max(left[i-1],arr[i]);
         }
         for(int i=n-2;i>=0;i--){
              right[i]= max(right[i+1],arr[i]);
         }
         
       vector<int> mini(n) ;
         for(int i=0;i<n;i++){
             mini[i]=  min(left[i],right[i]) - arr[i] ;
         }
         
       int sum =0;
       for(int x:mini){
           sum+=x;
       }
        return sum;
    }
};