class Solution {
public:
       vector<string> ans;
    void solve(string &temp,int remaining_Open,int remaining_Close){
        if(remaining_Open <=0 && remaining_Close<=0){
            ans.push_back(temp);
            return;
        }
        
        // Case 1 When remaining Open brackets is greater than zero 
        if(remaining_Open>0){
              temp.push_back('(');
            solve(temp,remaining_Open-1,remaining_Close);
              // Backtracking
             temp.pop_back();
        }
         // Case 2 When remaining close brackets is more than remaining open brackets 
          if(remaining_Close > remaining_Open ){
              temp.push_back(')');
            solve(temp,remaining_Open,remaining_Close-1);
              // Backtracking
             temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
     
        string temp="";
        int remaining_Open =n;
        int remaining_Close =n;
        solve(temp,remaining_Open,remaining_Close);
        return ans;
    }
};