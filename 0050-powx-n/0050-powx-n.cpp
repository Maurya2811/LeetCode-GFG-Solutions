class Solution {
public:
    
    double solve(double x, long n){
        if(n==0)
            return 1;
        if(n<0)
            return solve( 1/x , -n );
            
       if(n&1)
           return x* solve(x*x, n/2 );
                  
     return solve(x*x,n/2);   
 }
    
    double myPow(double x, int n) {
        
        if(x==0)
            return 0;
       
        return solve(x,n);
        
    }
};