class Solution {
public:
    int arr[47];
    
    int solve(int steps,int &n){
        if(steps>n)
            return arr[steps]=0;
        
        if(steps==n)
            return arr[steps]=1;
        
        if(arr[steps]!=-1)
             return arr[steps];
        
        return  arr[steps]= solve(steps+1,n) + solve(steps+2,n);
    }
    
    int climbStairs(int &n) {
        memset(arr,-1,sizeof(arr));
        return solve(0,n);
    }
};