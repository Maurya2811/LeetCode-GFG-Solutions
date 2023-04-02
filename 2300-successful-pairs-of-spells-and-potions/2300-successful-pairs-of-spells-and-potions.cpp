class Solution {
public:
    int searchLowerIdx(int left,int right,vector<int>& potions,int minPotion){
        int possibleIndex = -1;
        int mid = 0;
        while(left<=right){
             mid =  left + (right-left)/2;  
            if( potions[mid] >= minPotion){
                possibleIndex =mid;
                right =mid-1;
            }
            else {
                left =mid+1;
            }
                
        }
        return possibleIndex;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int potionSize = potions.size();
          int spellSize = spells.size();
        
        sort(potions.begin(),potions.end());
        
        int maxPotionValue = potions[potionSize-1];
         
        vector<int> answer ;
        for(int i=0;i<spellSize;i++){
            
            int spell =spells[i];
            // minPotion * spell >= success
            long long minPotion = ceil((1.0 * success)/spell);
            
            if(minPotion > maxPotionValue){
                answer.push_back(0);
                continue;
            }
            
            int index = searchLowerIdx(0,potionSize-1,potions,minPotion);
            int count = potionSize-index;
            
            answer.push_back(count);
        }
        return answer;
    }
};