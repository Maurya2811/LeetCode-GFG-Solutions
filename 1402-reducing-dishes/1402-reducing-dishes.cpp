class Solution {
public:
    int size;
    int memory[501][501];
    int solve(vector<int>& satisfaction,int i,int time){
        
        if(i>=size)
            return 0;
        if(memory[i][time]!=-1)
            return memory[i][time];
        
        int include = satisfaction[i]*time + solve(satisfaction,i+1,time+1);
        
        int exclude =  solve(satisfaction,i+1,time);
        
        return memory[i][time]= max(include ,exclude);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
          size=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        memset(memory,-1,sizeof(memory));
        return solve(satisfaction,0,1);
    }
};