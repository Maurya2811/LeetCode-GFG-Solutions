
// Brute Force

/*
class Solution {
public:
    vector<int> countBits(int n) {
       
        vector<int> ans;
        ans.push_back(0);
        
        for(int i=1;i<=n;i++){
            int t=i;
            int count =0;
            while(t){
                if((t&1)==1){
                     count++;
                }   
                  t = t>>1;
            }
            ans.push_back(count);
        }        
        return ans;
    }
    
};
*/


// Observation
// Digit is Odd then NO. of 1 in their 
//binary representation = 1 + #1 in (n/2);

class Solution {
public:
    
    vector<int> countBits(int n) {
          vector<int> ans;
        ans.push_back(0);
        
        for(int i=1;i<=n;i++){
            if(i&1){
                ans.push_back(1+ans[i>>1]);
            }else{
                ans.push_back(ans[i/2]);
            }
        }
        return ans;
    }
};

