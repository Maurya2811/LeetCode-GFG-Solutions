class Solution {
public:
    double dp[101][101];
    double solve(double poured, int i, int j){
        if(i<j || i<0 || j<0)
            return 0.0;
        
        if(i==0 && j==0)
            return poured;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        double leftUp =   (solve(poured,i-1,j-1)-1)/2.0 ;
                
        double rightUp = (solve(poured,i-1,j)-1)/2.0 ;
        
        if(leftUp<0){
            leftUp =0.0;
        }
        if(rightUp<0){
            rightUp =0.0;
        }

        return dp[i][j]=leftUp+rightUp;
    }
    
    double champagneTower(int poured, int query_row, int query_glass) {
         
       for(int i=0;i<101;i++){
           for(int j=0;j<101;j++){
               dp[i][j]=-1;
           }
       }
        
        return min(1.0, solve(poured,query_row,query_glass));
    }
};