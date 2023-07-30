class Solution {
public:
    
    vector<pair<int,int>>serves ={{100,0},{75,25},{50,50},{25,75}};
    vector<vector<double>> dp;
    double find_probability(int A, int B){
        
         if(A<=0 && B<=0)
             return 0.5;
         if(A<=0)
             return 1;
        if(B<=0)
            return 0;
        
        if(dp[A][B]!=-1.0)
            return dp[A][B];
        
        double probability =0.0;
        
        for(auto x:serves){
           int taking_A = A-x.first;
           int taking_B = B-x.second;
           probability += find_probability(taking_A,taking_B);
            
        }
        
        return dp[A][B]=0.25*probability;
        
    }
    double soupServings(int n) {

 
        if(n>=5000)         // Probability of A will be almost 1 if n value if so large
            return 1.0;
        
       dp.resize(n+1,vector<double>(n+1,-1.0));
        
        return find_probability(n,n);
    }
};