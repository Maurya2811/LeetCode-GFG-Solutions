class Solution {
public:
    // Previous Smaller Element
    void leftLimit(vector<int>& heights, vector<int>&left){
          stack<int> st;int n=heights.size();
        st.push(-1);
        
        for(int i=0;i<n;i++){
            int curr=heights[i];
          while(st.top()!=-1 && heights[st.top()]>=curr){
              st.pop();
          }
            left[i]=st.top();
            st.push(i);
        }
         
    }
    
    // Next Smaller Element
    void rightLimit(vector<int>& heights, vector<int>&right){
          stack<int> st;
        int n=heights.size();
        st.push(-1);
       
        for(int i=n-1;i>=0;i--){
            int curr=heights[i];
           
            
                while(st.top()!=-1  && heights[st.top()]>=curr){
              st.pop();
          }
            right[i]=st.top();
            st.push(i);
        }
         
    }
    
    
    int largestRectangleArea(vector<int>& heights) {
        // We need to find the right boundary and left boundary for every bar.
       
        int area=0,max_area=0;
        int n=heights.size();
    vector<int> left(n);
        leftLimit(heights,left);
      vector<int> right(n);
        rightLimit(heights,right);
        
        for(int i=0;i<n;i++){
            if(right[i]==-1)
                right[i]=n;
            
            
            area=(right[i]-left[i]-1)*heights[i];
                   //     lenght    x   breadth  
            
            max_area =max(max_area,area);
        }
        return max_area;
    }
};