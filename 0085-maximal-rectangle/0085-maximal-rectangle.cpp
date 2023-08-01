class Solution {
public:
    
    int n; 
    // true => NSL and false => NSR
    void nearestGreaterEle(vector<int>&temp ,vector<int>& heights, int pseudo_idx, bool NSL_Or_NSR){
        stack<pair<int,int>> st;  // <value,index>
        if(NSL_Or_NSR){
             for(int i=0 ; i<n ; i++){
                 if(st.empty()){
                     temp.push_back(pseudo_idx);
                 }
                 else if(!st.empty() && st.top().first < heights[i]){
                      temp.push_back(st.top().second);
                 }
                   else if(!st.empty() && st.top().first >= heights[i]){
                       while(!st.empty() && st.top().first >= heights[i]){
                                               st.pop();
                     }
                        if(st.empty()){
                            temp.push_back(pseudo_idx);
                        }
                       else
                           temp.push_back(st.top().second);
                   }    
                st.push({heights[i],i});
             }
        }
        else{
            // st.clear();
            stack<pair<int,int>> st2;
            for(int i=n-1 ; i>= 0; i--){
                 if(st2.empty()){
                     temp.push_back(pseudo_idx);
                 }
                 else if(!st2.empty() && st2.top().first < heights[i]){
                      temp.push_back(st2.top().second);
                 }
                  else if(!st2.empty() && st2.top().first >= heights[i]){
                       while(!st2.empty() && st2.top().first >= heights[i]){
                                               st2.pop();
                     }
                        if(st2.empty()){
                            temp.push_back(pseudo_idx);
                        }
                       else
                           temp.push_back(st2.top().second);
                   }    
                st2.push({heights[i],i});
             }
        }
       
    }
    
    int MAH(vector<int>& heights) {
        n = heights.size();
   vector<int> left,right ;
        nearestGreaterEle(left,heights,-1,true);
        nearestGreaterEle(right,heights,n,false);
        
        reverse(right.begin(),right.end());
     
        int Maxi=0;
      // vector<int> ans(n);
        
         for(int i=0; i<n;i++ ){
             // ans[i] = (right[i]-left[i]-1)*heights[i];
          int x = (right[i]-left[i]-1)*heights[i];

              // Maxi = max(Maxi,ans[i]);
                  Maxi = max(Maxi,x);

         }
        cout<<Maxi<<"rcurson"<<endl;
        
        return Maxi;
        
    }


    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int N=matrix[0].size();
        
        vector<int> temp;
        
        for(int i=0;i<N;i++){
            temp.push_back(matrix[0][i]-'0');
        }
        
        int Mx = MAH(temp);
        // cout<<Mx<<endl;
        
        for(int i=1;i<m;i++){
            
            for(int j=0;j<N;j++){
                
                if(matrix[i][j]=='0'){
                    temp[j]=0;
                }
                else{
                    temp[j]= temp[j]+ (matrix[i][j]-'0');
                }
                
            }
             Mx = max(Mx,MAH(temp));          
        }
        return Mx;
    }
};