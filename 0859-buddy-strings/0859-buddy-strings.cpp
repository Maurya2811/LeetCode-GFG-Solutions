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
        cout<<swapNeed.size();
        if(swapNeed.size()==2){
            swap(s[swapNeed[0]],s[swapNeed[1]]);
                   if(s==goal)
                   return true;
                   else return false;
        }
                   return false;
            
    }
};