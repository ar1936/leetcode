// class Solution {
// public:
//     int findPeakElement(vector<int>& arr) {
//         int lo=0,hi=arr.size()-1;
//         while(lo<hi-1){
//             int mid=lo+(hi-lo)/2;
//             if(arr[mid]<arr[hi])
//                 lo=mid+1;
//             else if(arr[mid]>arr[hi])
//                 hi=mid;
//         }
//         return hi;
//     }
// };

class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int low=0,n=a.size(),high=n-1,mid;
        if(n==1) return 0;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(mid==0 && a[mid]>a[mid+1]) return mid;
            if(mid==n-1 && a[mid-1]<a[mid]) return mid;
            if(mid<n-1 && a[mid]>a[mid+1] && a[mid]>a[mid-1]) return mid;
            if(mid>0 && a[mid]<a[mid-1]) high=mid-1;
            else low=mid+1;
        }
        return -1;
    }
};