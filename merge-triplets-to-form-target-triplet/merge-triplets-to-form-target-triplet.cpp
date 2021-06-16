            // My try

// class Solution {
// public:
//     bool mergeTriplets(vector<vector<int>>& A, vector<int>& B) {
//         bool f1=false,f2=false,f3=false;
//         sort(A.begin(),A.end());
//         vector<vector<int>>v;
//         for(int i=0;i<A.size();i++){
//             if(B[0]==A[i][0]||B[1]==A[i][1]||B[2]==A[i][2])
//               v.push_back(A[i]);
//         }
//         sort(v.begin(),v.end());
//         vector<int>v1(3);
//         for(int i=0;i<v.size();i++){
//             v1[0]=max(v1[0],v[i][0]);
            
//             v1[1]=max(v1[1],v[i][1]);
            
//             v1[2]=max(v1[2],v[i][2]);
//             if(v1==B)
//                 return true;
//         }
//         return false;
        
//     }
// };



class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& A, vector<int>& B) {
        vector<int>ans(3);
        for(auto i:A){
            if(i[0]<=B[0]&&i[1]<=B[1]&&i[2]<=B[2]){
                ans={max(ans[0],i[0]),max(ans[1],i[1]),max(ans[2],i[2])};
            }
        }
        return ans==B;
    }
};

