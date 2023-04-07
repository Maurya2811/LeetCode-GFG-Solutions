class Solution {
public: 

   vector<string> ans;
    
    void solve(int index, string &output,string &digits,vector <string> &map){
        if(index>=digits.length()){
            ans.push_back(output);
            return;
        }
        
        int value = digits[index]-'0';
        string temp=map[value];
        for(int i=0;i<temp.length();i++){
            
            // Including 1st char
            output.push_back(temp[i]);
            // Recursive Solution
            solve(index+1,output,digits,map);
            // backtracking
             output.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0){
            return ans;
        }
 vector <string> map(10);
    map[2]="abc";
    map[3]="def";
    map[4]="ghi";
    map[5]="jkl";
    map[6]="mno";
    map[7]="pqrs";
    map[8]="tuv";
    map[9]="wxyz";
    
        int index=0;
        string output="";
        solve(index,output,digits,map);
        return ans;
    }
};