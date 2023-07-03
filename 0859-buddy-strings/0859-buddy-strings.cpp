class Solution {
public:
    int n,m;
    bool freqChk(string s){
         int arr[26] = {0};
        
        for(char &ch : s) {
            arr[ch-'a']++;
            
            if(arr[ch-'a'] > 1) {
                return true;
            }
        }
        
        return false;
    }
    bool buddyStrings(string &s, string &goal) {
        int n = s.length();
        int m= goal.length();
        
        if(n!=m){
            return false;
        }
       
        if(s==goal){
            return freqChk(s);
        }
        vector<int>swapNeed;
        
        for(int i=0;i<n;i++){
            if(s[i]!=goal[i]){
                swapNeed.push_back(i);
            }
        }
      if(swapNeed.size() != 2)
            return false;
        
        int first  = swapNeed[0];
        int second = swapNeed[1];
        
        swap(s[first], s[second]);
        return s==goal;       
            
    }
};