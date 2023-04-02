class Solution {
public:
    
    void solve(string &s, string &part){
        int found= s.find(part);
        if(found!=string :: npos){
            string left_part=s.substr(0,found);   // string.substr(starting index , no. of chars )
            string right_part=s.substr(found+part.length(),s.size()); // s.substr( idx, max it can go to the last index )
            s= left_part + right_part ;
            
            solve(s,part);
        }
        else {
            // since all occurances has been removed
            return;
        }
    }
    string removeOccurrences(string s, string &part) {
        
      /*  //Using Iteration
        
        int pos=s.find(part);
        while(pos!= string::npos)
        {
            s.erase(pos,part.length());
            pos=s.find(part);
        }
        return s;
        
    */   
        // Usig Recursion
         
        solve(s,part);
        return s;
        
    }
}; 