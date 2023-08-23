//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
      int row,col; 
    vector<pair<int,int>> directions ={ {0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
    
    bool wordFound(int &x,int &y,vector<vector<char>>&grid ,string &word ){
        
        for(auto &dir: directions){
           
            int new_x = x;
            int new_y = y;
            int i=0;
            while(new_x >=0 && new_x < row && new_y >=0 && new_y < col && word[i]==grid[new_x][new_y] ){
                new_x += dir.first;
                new_y += dir.second;
                if(i==word.length()-1)
                        return true;
                i++;
                if(new_x >=0 && new_x < row && new_y >=0 && new_y < col && word[i]==grid[new_x][new_y]){
                    if(i==word.length()-1){
                        return true;
                    }
                }
            }
        }
        return false;
    }
	vector<vector<int>>searchWord(vector<vector<char>>&grid, string &word){
	     vector<vector<int>>coordinates;
	         row = grid.size();
	         col = grid[0].size();
	     int k = word.length();
	     
	     if(k> row && k>col){
	         return{};
	     }
	     
	     for(int i=0;i<row;i++){
	         for(int j=0;j<col;j++){
	             if(wordFound(i,j,grid,word)){
	                 coordinates.push_back({i,j});
	             }
	         }
	     }
	     return coordinates;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends