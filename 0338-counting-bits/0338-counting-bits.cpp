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