// Brute Force TLE
/*
class Solution {
public:
    void solve(int i, vector<bool> &bulb ){
        if(i>bulb.size())
            return;
        
        for(int j=i-1;j<bulb.size();j+=i){
            bulb[j]=!bulb[j];
        }
        solve(i+1,bulb);
    }
    int bulbSwitch(int n) {
        vector<bool> bulb(n,false);
        solve(1,bulb);
        int count=0;
        for(bool x: bulb){
            if(x)
                count++;
        }
        return count;
    }
};
*/

// Optimized
// Perfect Squares has Odd no. of factors 
// Odd -> Bulb Open  & Even -> Bulb Closed
class Solution {
public:
    
    
    int bulbSwitch(int n) {
       int count=0;
        for(int i=1;i*i <=n ; i++){
            count++;
        }
        return count;
    }

};


