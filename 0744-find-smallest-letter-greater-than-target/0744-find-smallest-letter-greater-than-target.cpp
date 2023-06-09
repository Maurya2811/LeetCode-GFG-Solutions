class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int idx = 0;
        
//         int s=0, e = letters.size()-1;
//         int idx = 0;
//         while(s<=e){
//             int mid= s + (e-s)/2;
//             if(target<letters[mid]){
//                 idx=mid;
//                 e=mid-1;
//             }
//             else{
//                 s=mid+1;
//             }
//         }
//         return letters[idx];
        
         idx = upper_bound(letters.begin(),letters.end(),target)-letters.begin();
           return idx==letters.size() ? letters[0]:letters[idx];
         // return letters[idx];
    }
};