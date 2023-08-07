class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int key) {
       ios_base::sync_with_stdio(false);
cin.tie(NULL);
        int row=mat.size(),col=mat[0].size();
        int s=0,e=row*col-1;
        while(s<=e)
        {
           int m = s+ (e-s)/2;
            
            int val=mat[m/col][m%col];
            
            if(val==key)
            return true;
            else if(key<val)
            e=m-1;
            else
            s=m+1;

        }
         return false;
    }
};