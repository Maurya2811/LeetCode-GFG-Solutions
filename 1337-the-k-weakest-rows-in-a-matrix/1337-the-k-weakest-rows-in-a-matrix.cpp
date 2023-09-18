class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        int row = mat.size();
        vector<pair<int,int>> vec;
        
        for(int j=0; j < row ;j++){
            int countOne=0;
            for(int i=0;i<mat[j].size();i++){
                if(mat[j][i]==1){
                    countOne++;
                }
            }
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