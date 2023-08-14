class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
       long long int xy =0; // xy will contain the xor of the two unique number
       for(int &x:nums){
           xy^=x;
       }
       xy= (~xy + 1)& xy ;  
    // Used to find the first set bit or the first different bit between the two nos
     
        // long long int lastBit =(xy & (xy - 1)) ^ xy;
       
       vector<int> vec ={0,0};
       for(int &x:nums){
           if(xy&x)
               vec[0]^=x;
           else
              vec[1]^=x;
       }
       
       return vec;
    }
};