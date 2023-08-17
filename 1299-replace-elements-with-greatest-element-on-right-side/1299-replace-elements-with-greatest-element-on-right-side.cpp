class Solution {
public:
    vector<int> replaceElements(vector<int>& a) {
        int n = a.size();
         vector<int> ans;
       int maxi =-1;
         ans.push_back(-1);
       for(int i=n-1;i>0;i--){
             maxi = max(maxi,a[i]);
           if(a[i]>=maxi){
               ans.push_back(a[i]);
           }
           else
            ans.push_back(maxi);
        
       }
       reverse(ans.begin(),ans.end());
             
       return ans;
    }
};