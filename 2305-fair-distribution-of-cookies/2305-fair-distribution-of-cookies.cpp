// class Solution {
// public:
//     int n;
//     int result = INT_MAX ;
    
//     void solve(vector<int>& cookies,vector<int>&child, int k,int j){
//         if(j>=n){
//             int unfairness = *max_element(child.begin(),child.end());
//             result = min(result,unfairness);
//             return;
//         }                 
       

//         int cookie = cookies[j];
        
//         for(int i=0;i<k;i++){
//             child[i]+=cookie ;
//             solve(cookies,child,k,j+1);
//             child[i]-=cookie;
//         }

//     }
//     int distributeCookies(vector<int>& cookies, int k) {
//         n = cookies.size();
//         vector<int> child (k,0);
        
//         solve(cookies,child,k,0);
        
//         return result;
    
//     }
// };
class Solution {
public:
    int ans = INT_MAX;
    void solve(int start, vector<int>& nums, vector<int>& v, int k){
        if(start==nums.size()){
            int maxm = INT_MIN;
            for(int i=0;i<k;i++){
                maxm = max(maxm,v[i]);
            }
            ans = min(ans,maxm);
            return;
        }
        for(int i=0;i<k;i++){
            v[i] += nums[start];
            solve(start+1,nums,v,k);
            v[i] -= nums[start];
        	if(v[i]==0) break;

        }
    }
    
    int distributeCookies(vector<int>& nums, int k) { // nums is the cookies vector
        int n = nums.size();
        vector<int> v(k,0); // v is to store each sum of the k subsets
        solve(0,nums,v,k);
        return ans;
    }
};