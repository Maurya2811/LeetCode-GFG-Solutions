// Using Maths
 /*
     int numSquares(int n) {
        if (ceil(sqrt(n))==floor(sqrt(n))) return 1;

        int a = n;
        while(a%4==0) a/=4;
        if(a%8==7) return 4;

        for(int i=1;i*i<=n;i++){
            if(ceil(sqrt(n-i*i))==floor(sqrt(n-i*i))) return 2;
        }

        return 3;
    }
    */
class Solution {
public:
     int dp[10001];
    int solve(int n){
        if(n==0)
            return 1;  // It is Equal to sum
       
        if(n<0)
            return 0;// It will not give the sum == n
        
        if(dp[n]!=-1)
            return dp[n];
        int ans=INT_MAX;
        int count=0;
        int i=1;  // 1 square + 2 square + 3 square
        while(i<= sqrt(n)){
             count = 1 + solve (n- i*i);
           
            ans=min(ans,count);
             dp[n]=ans;
            i++;
        }
        
        return ans;
    } 
    
    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        
        return solve(n)-1;
        
        
    }
    
   
};