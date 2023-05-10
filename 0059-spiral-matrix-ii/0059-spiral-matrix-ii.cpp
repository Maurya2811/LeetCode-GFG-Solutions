class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n,vector<int>(n));
        int top=0,left=0;
        int right=n-1,down=n-1;
        int direction=0;
        int count=1;
        while(left <= right && top <= down){
            
            if(direction==0){
                for(int i=left;i<=right;i++){
                    mat[top][i]=count++;
                }
                top++;
            
            }
            
           else if(direction==1){
                for(int i=top;i<=down;i++){
                    mat[i][right]=count++;
                }
               right--;
               
            }
            else if(direction==2){
                for(int i=right;i>=left;i--){
                    mat[down][i]=count++;
                }
                down--;
           
            }
            else if(direction==3){
                for(int i=down;i>=top;i--){
                    mat[i][left]=count++;
                }
                left++;
               
            }
            
            direction ++;
            
            if(direction==4){
                direction=0;
            }
        }
        return mat;
    }
};