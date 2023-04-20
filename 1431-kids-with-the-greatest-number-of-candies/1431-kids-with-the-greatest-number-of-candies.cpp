class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        // Finding max Element
        int maxi= *max_element(candies.begin(),candies.end());
      
          vector<bool> v(candies.size());
        for(int i=0;i<v.size();i++){
            if(candies[i]+extraCandies >= maxi){
                v[i]=true;
            }
        }
        return v;
    }
};