class Solution {
public: 
    int memory[366];
     int solve(vector<int>& days, vector<int>& costs,int &n,int i){
         
         if(i>=n)
            return 0; // You cant travel, so no cost
         if(memory[i]!=-1){
               return memory[i];   
         }
         
         // 1-day Pass
         int cost_1 = costs[0]+solve(days,costs,n,i+1);
         
         // 7-day Pass
            int j=i;
         int max_day = days[i]+7;
         while(j<n && days[j]<max_day){
             j++;
         }
         int cost_7 = costs[1] + solve(days,costs,n,j);
         
          // 30-day Pass
          j=i;
         max_day = days[i]+30;
         while(j<n && days[j]<max_day){
             j++;
         }
         int cost_30 = costs[2] + solve(days,costs,n,j);
         
         return memory[i]= min({cost_1,cost_7,cost_30});
     }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        memset(memory,-1,sizeof(memory));
        return solve(days,costs,n,0);
    }
};