class Solution {
public:
    double solve(double x, long n){
        if(n==0) return 1.0;

        if(n<0){
            n = -1 * n;
            x = 1.0 / x;
        }

        double result = 1;
        while(n>0){
            if(n%2==1){
                result = result*x;
                n--;
            }
            x = x*x;
            n = n/2;
        }
        return result;
    }
    
/*    
    double solve(double x, long n){
        if(n==0)
            return 1;
        if(n<0)
            return solve( 1/x , -n );
            
       if(n&1)
           return x* solve(x*x, n/2 );
                  
     return solve(x*x,n/2);   
 }
 */  
    double myPow(double x, int n) {
        
        if(x==0)
            return 0;
       
        return solve(x,n);
        
    }
};

 