class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int sum=0;
        if(n&1){
            for(int i=0;i<n;i++)
                sum+=mat[i][i];
            for(int i=n-1;i>=0;i--)
              if(i!=(n/2)){
                  sum+=mat[n-1-i][i];
              }      
        }
        else{ 
             for(int i=0;i<n;i++)
                sum+=mat[i][i];
            for(int i=n-1;i>=0;i--)
               sum+=mat[n-1-i][i]; 
                   
        }
        return sum;
    }
};