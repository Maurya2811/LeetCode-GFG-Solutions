class Solution {
public:
    int arraySign(vector<int>& nums) {
        int negCount=0;
        // bool isZero = false;
         for(auto &x: nums){
             if(x<0)
                 negCount++;
             else if(x==0){
                 return 0;
                 // isZero = true;
             }
         }
        // if(isZero)
        //     return 0;
       if(negCount%2==0){
            return 1;
        }
        return -1;
    }
};