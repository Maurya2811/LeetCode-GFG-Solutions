class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        vector<int> v;
       int row = m.size(); 
       int col = m[0].size();
        int left=0,right=col-1,top=0,bottom=row-1,i;
        int count=0,t_element=row*col;
     /*    while(left<=right && top<=bottom)
        {
            for(i=left;i<=right;i++)
            {
               v.push_back(m[top][i]);
            }
            top++;
            for(i=top;i<=bottom;i++)
            {
               v.push_back(m[i][right]);
            }
            right--;
            if(top<=bottom){
            for(i=right;i>=left;i--)
            {
               v.push_back(m[bottom][i]);
            }
            bottom--;
            }
            if(left<=right){
            for(i=bottom;i>=top;i--)
            {
               v.push_back(m[i][left]);               
            }
            left++;
            }
         }   */

         while(count < t_element)
         {
             for(i=left;i<=right && count<t_element  ;i++)
             {
                 v.push_back(m[top][i]);
                 count++;
             }
             top++;
             for(i=top;i<=bottom && count<t_element;i++)
             {
                 v.push_back(m[i][right]);
                 count++;
             }
             right--;
             for(i=right;i>=left && count<t_element;i--)
             {
                 v.push_back(m[bottom][i]);
                 count++;
             }
             bottom--;
             for(i=bottom;i>=top && count<t_element;i--)
             {
                 v.push_back(m[i][left]);
                 count++;
             }
             left++;
             
         }
        return v;
    }
};