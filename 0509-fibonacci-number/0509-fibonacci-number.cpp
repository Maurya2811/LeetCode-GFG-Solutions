class Solution {
public:
    int fib(int n) {
         if(n==0)
        return 0;
        if(n<3)
        return 1;
     
        
        int first=0,second =1;
         int sum=0;
        
        while(n>1){
            sum = (first+second);
            first = second;
            second = sum;
           n--;
        }
        return sum;
    }
};