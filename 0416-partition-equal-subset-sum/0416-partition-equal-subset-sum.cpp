class Solution {
public:
    int n;
    
    
  bool subsetSum(int n, vector<int>& arr, int sum){  
      if(n==0 && sum ==0 )
      return true;
      
      bool t[n+1][sum+1];
      
      // Initialization
      
      for(int j=0;j<sum+1;j++){
          t[0][j]=false;
      }
      
      for(int i=0;i<n+1;i++){
          t[i][0]=true;
      }
      
      
      // tabulation
      
      // t[n][sum] == t[i][j]  
      for(int i=1;i<n+1;i++){
          for(int j=1;j<sum+1 ; j++){
              if(j>= arr[i-1]){
                  t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
              }else
               t[i][j] =  t[i-1][j];
          }
      }
      
      return t[n][sum];
  }
  
    
    bool canPartition(vector<int>& arr) {
         
          n= arr.size();
        
        int totalSum =0;  
        totalSum =  accumulate(arr.begin(),arr.end(),0);
     
        if((totalSum & 1)==1){
            return 0;
        }
        
        return subsetSum(n,arr,totalSum>>1);
    }
};