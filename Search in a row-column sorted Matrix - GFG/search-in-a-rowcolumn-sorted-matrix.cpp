//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to search a given number in row-column sorted matrix.
    bool search(vector<vector<int> > &matrix, int n, int m, int x) 
    {
        // WE will traverse from TOP-RIGHT corner of the matrix 
        // if the Key is greater than MID then row++
        // if the key is less than MID the     col--;
        
        
        int i=0,j=m-1;
        
        while(j>=0 && i<n ){
            if(x== matrix[i][j])
               return true;
            else if(x>matrix[i][j]){
                i++;
            } else{
                j--;
            }  
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() 
{ 
	int t;
    cin>>t;
    while(t--)
    {

 		int n, m;
    	cin>> n>> m;
        vector<vector<int> > matrix(n);
            
        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        int x;
        cin>>x;
        Solution obj;
        if (obj.search(matrix,n,m,x)) 
            cout << "1\n"; 
        else
            cout << "0\n"; 
    }
	return 0; 
} 


// } Driver Code Ends