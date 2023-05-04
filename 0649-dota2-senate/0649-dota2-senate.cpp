//Approach-1 (Brute Force) - ACCEPTED
/*
class Solution {
public:

    bool removeSenator(string &senate, char ch, int idx) {
        bool loopAround = false;
        
        while(true) {
            
            if(idx == 0) {
                loopAround = true;
            }
            
            if(senate[idx] == ch) {
                senate.erase(begin(senate) + idx);
                break;
            }
            
            idx = (idx+1)%(senate.length());
            
        }
        
        return loopAround;
    }
    
    string predictPartyVictory(string senate) {
        
        int R_Count = count(begin(senate), end(senate), 'R');
        int D_Count = senate.length() - R_Count;
        
        
        int idx = 0;
        
        while(R_Count > 0 && D_Count > 0) {
            
            if(senate[idx] == 'R') {
                bool checkRemoval = removeSenator(senate, 'D', (idx+1)%(senate.length()));
                D_Count--;
                if(checkRemoval) {
                    idx--;
                }
            } else {
                bool checkRemoval = removeSenator(senate, 'R', (idx+1)%(senate.length()));
                R_Count--;
                if(checkRemoval) {
                    idx--;
                }
            }
            
            idx = (idx+1)%(senate.length());
            
        }
        
        return R_Count == 0 ? "Dire" : "Radiant";
        
    }
};
*/

//Approach-2 (Improved Brute Force)
class Solution {
public:
    int n;
    void removeSenator(string &senate, vector<bool>& removed, char ch, int idx) {
        
        while(true) {
            
            if(senate[idx] == ch && removed[idx] == false) {
                removed[idx] = true;
                break;
            }
            idx = (idx+1)%n;
        }

    }
    
    string predictPartyVictory(string senate) {
        
        n = senate.length();
        
        int R_Count = count(begin(senate), end(senate), 'R');
        int D_Count = n - R_Count;
        
        int idx = 0;
        
        //Initially no one removed
        vector<bool> removed(n, false);
        
        while(R_Count > 0 && D_Count > 0) {
            
            if(!removed[idx]) {
            
                if(senate[idx] == 'R') {
                    removeSenator(senate, removed, 'D', (idx+1)%n);
                    D_Count--;
                    
                } else {
                    removeSenator(senate, removed, 'R', (idx+1)%n);
                    R_Count--;

                }
            }
            idx = (idx+1)%n;
            
        }
        
        return R_Count == 0 ? "Dire" : "Radiant";
        
    }
};
