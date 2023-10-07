class Solution {
public:
   int N,M,K;
    const int MOD = 1e9+7 ;
   int dp[51][51][101];
   int solve(int idx, int size , int maxSoFar){
       
       if(idx==N){
           if(size==K){
               return 1;
           }
           return  0;
       }
          if(dp[idx][size][maxSoFar]!=-1)
             return dp[idx][size][maxSoFar];

          int result =0;

          for(int i=1;i<=M;i++){
              
              if(i>maxSoFar){
                  result = ( result + solve(idx+1,size+1,i))%MOD;
              }
              else{
                  result  = (result+solve(idx+1,size,maxSoFar))%MOD;
              }

          }
          return dp[idx][size][maxSoFar] = result;

   }
    int numOfArrays(int n, int m, int k) {
        
        N=n, M=m ,K=k;
        
        memset(dp,-1,sizeof(dp));

        return solve(0,0,0);



    }
};