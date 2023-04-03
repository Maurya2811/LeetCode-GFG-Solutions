//  Using Iteration  

class Solution {
public:
    
   
    int maxProfit(vector<int>& prices) {
       
        // Kadane's Algo
        int maxProfit=0;
        int diff,mini=prices[0];
        int size=prices.size(),i;
        for(i=0;i<size;i++)
        { 
              
             mini= min(prices[i],mini);

           diff=prices[i]-mini;
               maxProfit=max(diff,maxProfit);
        }
        return maxProfit;
    }
};

/*

// Using Recursion
class Solution {
public:
    
    void solve (vector<int>& prices, int &maxProfit , int &mini,int i){
        // Base case
        if(i==prices.size())
            return ;
        // Solving 1 case
         
         mini= min(prices[i],mini);
         int  diff=prices[i]-mini;
               maxProfit=max(diff,maxProfit);
        solve(prices,maxProfit , mini,i+1);
    }
    
    
    int maxProfit(vector<int>& prices) {
       
        // Using Recursion
         int maxProfit=0;
        int mini=prices[0];
        solve (prices,maxProfit , mini,0);
        return maxProfit;
        
        
    }
};
*/