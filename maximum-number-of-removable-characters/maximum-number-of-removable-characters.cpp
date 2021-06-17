class Solution {
    bool solve(string s,string p,vector<int>nums,int k){
        int i=0,j=0,n=s.size(),m=p.size();
        
        
        for(int i=0;i<k;i++){
            s[nums[i]]='?';
        }
        i=0;
        
        while(i<n&&j<m){
            if(s[i]==p[j])
                j++;
            i++;
        }
        return j==m;
    }
public:
    int maximumRemovals(string s, string p, vector<int>& nums) {
        int ans=0,low=0,high=nums.size();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(solve(s,p,nums,mid)){
                ans=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return ans;
    }
};


























































// class Solution {
//     bool solve(string s,string p,vector<int>nums,int k){
//         int i=0,j=0,n=s.size(),m=p.size();
//          //remove all element in s before k
        
//         for(int i=0;i<k;i++){
//             s[nums[i]]='?';
//         }
//         i=0;
//         //now check for subsequence 
        
//         while(i<n&&j<m){
//             if(s[i]==p[j])
//                 j++;
//             i++;
//         }
//         return j==m;
//     }
// public:
//     int maximumRemovals(string s, string p, vector<int>& nums) {
//         int ans=0,low=0,high=nums.size();
//         while(low<=high){
//             int mid=low+(high-low)/2;
//             if(solve(s,p,nums,mid)){
//                 ans=mid;
//                 low=mid+1;
//             }
//             else
//                 high=mid-1;
//         }
//         return ans;
//     }
// };