// class Solution {
// public:
//     int countTriplets(vector<int>& arr) {
//         int n=arr.size()+1,ans=0;
//         vector<int>pre(n);;
//         for(int i=1;i<n;i++){
//             pre[i]=pre[i-1]^arr[i-1];
//         }
//         for(int i=0;i<n;i++){
//             for(int k=i+1;k<n;k++){
//                 if(pre[i]==pre[k]){
//                     ans+=k-i-1;
//                 }
//             }
//         }
//         return  ans;
        
//     }
// };


class Solution {
public:
   int countTriplets(vector<int>& A) {
        int n = A.size(), res = 0, prefix = 0;
        unordered_map<int, int> count = {{0, 1}}, total;
        for (int i = 0; i < n; ++i) {
            prefix ^= A[i];
            res += count[prefix]++ * i - total[prefix];
            total[prefix] += i + 1;
        }
        return res;
    
        
    }
};



