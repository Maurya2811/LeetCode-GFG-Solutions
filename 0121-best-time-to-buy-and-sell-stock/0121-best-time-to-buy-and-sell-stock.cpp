class Solution {
public:
    int maxProfit(vector<int>& prices) {
         
        // Kadane's Algo
        int maxProfit=0;
        int diff,min=prices[0];
        int size=prices.size(),i,j;
        for(i=0;i<size;i++)
        { 
            if(prices[i]<min)  
             min=prices[i];

           diff=prices[i]-min;
               maxProfit=max(diff,maxProfit);
        }
        return maxProfit;
    }
};