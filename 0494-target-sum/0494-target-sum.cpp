class Solution {
public:
    
    // This problem is same as the
    // Count the no of the subset with a given diff
    
    
   int countOfSubsetSum(vector<int>& nums, int sum){
       int n= nums.size();
       
       vector<vector<int>> t(n+1,vector<int>(sum+1));
       
       for(int j=0;j<sum+1;j++){
           t[0][j]=0;
       }
       for(int i=0;i<n+1;i++){
           t[i][0]=1;
       }
       
       // t[n][sum] = t[i][j]
       //  n->i
       // sum->j
       for(int i=1;i<n+1;i++){
           for(int j=0;j<sum+1;j++){
               if(nums[i-1]<= j){
                   t[i][j] = t[i-1][j-nums[i-1]] + t[i-1][j];
               }
               else              
                   t[i][j] =  t[i-1][j];

           }
       }
       return t[n][sum];
   }
    int findTargetSumWays(vector<int>& nums, int target) {
         
         int TotalSum = accumulate(nums.begin(),nums.end(),0);
            
        
        
        if((TotalSum+ target)&1 || (TotalSum+target)<0 )
            return 0;
        
        int sum = (TotalSum+ target)>>1;
        
            if(sum < target ) return 0;
            
        
        return countOfSubsetSum(nums,sum);
        
    }
};