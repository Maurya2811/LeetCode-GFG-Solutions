class Solution {
public:
    int n;
    int result = INT_MAX ;
    
    void solve(vector<int>& cookies,vector<int>&child, int k,int j){
        if(j>=n){
            int unfairness = *max_element(child.begin(),child.end());
            result = min(result,unfairness);
            return;
        }                 
       

        int cookie = cookies[j];
        
        for(int i=0;i<k;i++){
            child[i]+=cookie ;
            solve(cookies,child,k,j+1);
            child[i]-=cookie;
        }

    }
    int distributeCookies(vector<int>& cookies, int k) {
        n = cookies.size();
        vector<int> child (k,0);
        
        solve(cookies,child,k,0);
        
        return result;
    
    }
};