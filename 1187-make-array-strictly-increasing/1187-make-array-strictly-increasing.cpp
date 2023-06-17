// class Solution {
// public:
//     int n;
//     map<pair<int,int>,int>mp;
//     int solve(int i,vector<int>& arr1, vector<int>& arr2,int prev){
//         if(i>=n)
//             return 0;
//         if(mp.find({i,prev}) != mp.end())
//             return mp[{i,prev}];
//         int result1 = 1e9 +1;
        
//         if(arr1[i]>prev){
//             result1 = solve(i+1,arr1,arr2,arr1[i]);
//         }
        
//       int result2 = 1e9 +1 ;
//         auto it = upper_bound(arr2.begin(), arr2.end(),prev);
//         if(it!= arr2.end()){
//             int idx = it - arr2.begin();
//             // arr1[i]=arr2[idx];
//             result2 = 1 + solve(i+1,arr1,arr2,arr2[idx]);
//         }
        
//         return mp[{i,prev}]=min(result1,result2);
//     }
//     int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
//         mp.clear();
//         sort(arr2.begin(), arr2.end());
//         n = arr1.size();
//         int result =solve(0,arr1,arr2,INT_MIN);
//         return result == 1e9+1 ? -1 : result;
//     }
// };
class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int ret=-1;
        set<int> s;
        unsigned size = arr2.size();
        for( unsigned i = 0; i < size; ++i ) s.insert( arr2[i] );
        arr2.assign( s.begin(), s.end() );
        int lower_idx[arr1.size()],upper_idx[arr1.size()];
        for (int i=0,j=0;i<arr1.size();i++){
            lower_idx[i]=lower_bound(arr2.begin(),arr2.end(),arr1[i])-arr2.begin();
            upper_idx[i]=upper_bound(arr2.begin(),arr2.end(),arr1[i])-arr2.begin();
            // printf("%d %d\n",lower_idx[i],upper_idx[i]);
        }
        //lins=last index after n swaps
        int vals[arr2.size()+1][arr1.size()], idx[arr2.size()+1][arr1.size()];
        memset(vals,-1,sizeof(int)*(arr2.size()+1)*arr1.size());
        memset(idx ,-1,sizeof(int)*(arr2.size()+1)*arr1.size());
        vals[0][0]=arr1[0];
        idx[0][0]=-2;
        for(int i=1;i<arr1.size();i++){
            if (arr1[i]>arr1[i-1]){
                vals[0][i]=arr1[i];
                idx[0][i]=-2;
            }else{
                break;
            }
        }
        for(int j=1;j<arr2.size()+1;j++){
            int i;
            vals[j][j-1]=arr2[j-1];
            idx[j][j-1]=j-1;
            for(i=j;i<arr1.size();i++){
                // no swap
                if (vals[j][i-1]!=-1 && vals[j][i-1]<arr1[i]){
                    vals[j][i]=arr1[i];
                    idx[j][i]=-2;
                }
                // try swap
                if (idx[j-1][i-1]!=-1){
                    int swap_idx;
                    if(idx[j-1][i-1]==-2){
                    // last item not swapped
                        swap_idx=upper_idx[i-1];
                    }else{
                    // last item swapped
                        swap_idx=idx[j-1][i-1]+1;
                    }
                    if(swap_idx!=arr2.size() && (arr2[swap_idx]<vals[j][i]||vals[j][i]==-1)){
                        vals[j][i]=arr2[swap_idx];
                        idx[j][i]=swap_idx;
                    }
                }
                if(idx[j][i]==-1) break;
            }
            if(i==arr1.size()){
                ret=j;
                break;
            }
        }
        // for(int j=0;j<arr2.size()+1;j++){
        //     for(int i=0;i<arr1.size();i++){
        //         printf("%4d",vals[j][i]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");
        // for(int j=0;j<arr2.size()+1;j++){
        //     for(int i=0;i<arr1.size();i++){
        //         printf("%4d",idx[j][i]);
        //     }
        //     printf("\n");
        // }
        return ret;
    }
};