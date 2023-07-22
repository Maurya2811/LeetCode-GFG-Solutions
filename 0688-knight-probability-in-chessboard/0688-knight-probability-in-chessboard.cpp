class Solution {
public:
    double dp[30][30][110];
    double recur(int n, int k, int row, int column){
        if(row<0 || column<0 || row>=n || column>=n){
            return 0;
        }
        if(k==0){return 1;}
        if(dp[row][column][k]){return dp[row][column][k];}
        double sum = 0.0;
        sum = recur(n,k-1,row-2,column-1)+
                recur(n,k-1,row-1,column-2)+
                recur(n,k-1,row+2,column+1)+
                recur(n,k-1,row+1,column+2)+
                recur(n,k-1,row-2,column+1)+
                recur(n,k-1,row+2,column-1)+
                recur(n,k-1,row-1,column+2)+
                recur(n,k-1,row+1,column-2);
        sum = sum / 8.0;
        return dp[row][column][k] = sum;
    }
    double knightProbability(int n, int k, int row, int column) {
        return recur(n,k,row,column);
    }
};