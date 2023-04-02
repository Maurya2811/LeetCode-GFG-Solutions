class Solution {
public:
  static bool mycomp(string a,string b){
       string s1= a+b;
       string s2= b+a;
      if(s1>s2)
          return true;
       return false;
   }
// customComparator must be static
    string largestNumber(vector<int>& nums) {
        vector<string> ans;
        for(auto x: nums){
            ans.push_back(to_string(x));
        }
        sort(ans.begin(),ans.end(),mycomp);
        if(ans[0]=="0") return "0";
        string st="";
         for(auto str: ans){
           st+=str;
        }
        return st;
    }
};