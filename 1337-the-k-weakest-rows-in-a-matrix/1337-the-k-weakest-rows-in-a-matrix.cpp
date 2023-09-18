class Solution {
public:
    
    int col;
    
    int countNoOfOne(vector<int>&arr){
        int s=0,e=col-1;
        int ans=-1;
        while(s<=e){
            int mid = (s+e)/2;
                        // cout<< mid<<" ";
            if(arr[mid]==1){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans+1;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        int row = mat.size();
        col = mat[0].size();
        vector<pair<int,int>> vec;
        
        for(int j=0; j < row ;j++){
            int countOne= countNoOfOne(mat[j]);
            
            // Linear Search
            
            // for(int i=0;i<col;i++){
            //     if(mat[j][i]==1){
            //         countOne++;
            //     }
            // }
            vec.push_back({countOne,j});
        }
        sort(vec.begin(),vec.end());
     vector<int>ans(k);
        
        for(int i=0;i<k;i++){
            ans[i]= vec[i].second;
        }
        return ans;
    }
};