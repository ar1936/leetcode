class Solution {
//     bool solve(vector<int>arr,int mid,int target){
//         long long count=mid*arr.size();
//         if(count>target)
//             return true;
//         return false;
//     }
// public:
//     int findBestValue(vector<int>& arr, int target) {
        
//         int lo=1,hi=1e9;
        
//         while(lo<hi){
//             int mid=lo+(hi-lo)/2;
//             if(solve(arr,mid,target))
//                 hi=mid;
//             else
//                 lo=mid+1;
//         }
//         return lo;
//     }
    public:
    int diff(int mid, vector<int>& arr, int target)
    {
        int sum = 0;
        for(int i = 0; i < arr.size(); i++)
            sum += min(mid, arr[i]);
        
        return abs(target - sum);
    }
    
    int findBestValue(vector<int>& arr, int target)
    {
        int n = arr.size();
        int s = 0;
        int e = target;
        
        while(s < e)
        {
            int mid = s + (e - s)/2;
            if(diff(mid, arr, target) <= diff(mid + 1, arr, target))
                e = mid;
            else
                s = mid + 1;
        }
        
        return s;
        
        
    }
};