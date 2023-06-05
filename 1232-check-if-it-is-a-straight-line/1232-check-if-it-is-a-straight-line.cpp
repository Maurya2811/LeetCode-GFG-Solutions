class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n=coordinates.size();
        
        int d_x = coordinates[1][0] - coordinates[0][0];
        
        int d_y = coordinates[1][1] - coordinates[0][1];
        
          /*
              _y = y2 - y1
               d_x   x2 - x1
             slope = d_y / d_x 
        */  
              
       /*        Our Code will terminate if 
                     d_x == 0 
         So , we cross multiply each other
             slope =  dy_i / dx_i ==  d_y / d_x   
                   =>  dy_i * d_x ==  d_y * dx_i
       
      */  
        for(int i=1;i<n;i++){
            
            int dy_i = coordinates[i][1] - coordinates[0][1];
            int dx_i = coordinates[i][0] - coordinates[0][0];
            
            if( dy_i * d_x !=  d_y * dx_i )
                return false;
        }
        return true;
    }
};