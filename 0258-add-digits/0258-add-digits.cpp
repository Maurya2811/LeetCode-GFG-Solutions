// 2 Approaches
//1. Brute Force
class Solution {
public:
    int sum=0;
    int countOfDigits(int num){
        sum=0;
        int count=0;
         while(num){
            sum+=num%10;
            num/=10;
             count++;
        }
        return count;
    }
    int addDigits(int num) {
        while(countOfDigits(num)>1){
            num=sum;
        }
        
       return sum; 
    }
};