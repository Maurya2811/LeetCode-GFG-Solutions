class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rev =0;
       int j=31;
       for(int i=0;i<32;i++){
           
           uint32_t bit = n & (1<<i) ;
            if(bit)
            rev |=  ( 1 <<j);
          
           j--;
       }
        return rev;
    } 
};
