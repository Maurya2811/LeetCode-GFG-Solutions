//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution {
public:
  int n,m;
  vector<pair<int,int>> directions = {{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
  vector<vector<bool>>evenMatrix ;
  void evenZeroMatrix(vector<vector<int>> &matrix,vector<vector<bool>>&evenMatrix){
       for(int i=0;i<m;i++ ){
           for(int j=0;j<n;j++){
               int count = 0;
               if(matrix[i][j]==1){
               for(auto &dir: directions){
                   int new_x = i+dir.first;
                   int new_y = j+dir.second;
                   if(new_x >=0 && new_x < m && new_y >=0 && new_y<n && matrix[new_x][new_y]==0){
                       count++;
                   }
               }
               if(  count>0 && (count&1)==0 ){
                   evenMatrix[i][j]=true;
                 }
                   
               }
           }
       }
  }
  
//   void print(vector<vector<bool> >& arr){
//       for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//               cout<<arr[i][j]<<" ";
//                   }
//                   cout<<endl;
//                 }
//     }
    int Count(vector<vector<int> >& matrix) {
        // Code here
         m = matrix.size();
         n = matrix[0].size();
         
         evenMatrix.resize(m,vector<bool>(n,false));
        evenZeroMatrix(matrix,evenMatrix);
        
        // print(evenMatrix);
        int ans =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (matrix[i][j] == 1 && evenMatrix[i][j]) {
                     ans++;
                  } 
                }
            }
        return ans;
    }
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends