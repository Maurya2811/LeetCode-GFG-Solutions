// Using Max Heap
class Solution {
public:
    typedef pair<int,char> P;
    string reorganizeString(string s) {
        int n = s.length();
        if(n==1){
            return s;
        }
        vector<int> arr(26,0);
        
        for(char &ch: s){
            arr[ch-'a']++;
            if(arr[ch-'a'] > (n+1)>>1){
                return "";
            }
        }
        
        priority_queue<P,vector<P>> que;
        
        for(char i='a' ; i<='z';i++){
            if(arr[i-'a']>0)
            que.push({arr[i-'a'],i});
        }

        string ans="";
        
       while(que.size()>=2){
           auto str1 = que.top();
           que.pop();
           
           auto str2 = que.top();
           que.pop();
           
           ans = ans + str1.second + str2.second;
           str1.first--;
           str2.first--;
           
           if(str1.first>0){
               que.push(str1);
           }
           if(str2.first>0){
               que.push(str2);
           }
       }
        if(!que.empty()){
            ans+=que.top().second;
        }
        return ans;
    }
};