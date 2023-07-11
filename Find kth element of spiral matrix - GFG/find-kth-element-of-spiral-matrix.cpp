//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int matrix[MAX][MAX],int m,int n,int k)
    {
 		// Your code goes here.
 		
 	      int top=0,left=0;
        int down=m-1,right=n-1;
        vector<int> arr;
         int direction=0;
         int count=0;
        while(left<=right && top<=down){
            
           if(direction==0){
            for(int i=left;i<=right;i++){
                
                count++;
                if(count==k)
                return (matrix[left][i]);
            }
               top++;
    
            }
            
             if(direction==1){
            for(int i=top;i<=down;i++){
                count++;
                if(count==k)
                return (matrix[i][right]);
            }
               right--;
            
            }
            
             if(direction==2){
            for(int i=right;i>=left;i--){
                count++;
                if(count==k)
                return (matrix[down][i]);
            }
               down--;
           
            }
            
             if(direction==3){
            for(int i=down;i>=top;i--){
                count++;
                if(count==k)
                return (matrix[i][left]);
            }
               left++;
          
            }
                 direction++;
            if(direction==4){
                direction =0;
            }
        }
 		return -1;
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends