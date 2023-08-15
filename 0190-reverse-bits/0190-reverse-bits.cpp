class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rev =0;
       int j=31;
       for(int i=0;i<32;i++){
          int mask = 1<<i;
           
           if(n&mask){
               int smask = 1<< j;
               rev|=smask;
           }
           j--;
       }
        return rev;
    } 
};
// class Solution {
// public:
//     uint32_t  reverseBits(uint32_t n) {
//         uint32_t result= 0;
//         for(int i=0; i<32; i++)
//             result = (result<<1) + (n>>i &1);
        
//         return result;
//     }
// };