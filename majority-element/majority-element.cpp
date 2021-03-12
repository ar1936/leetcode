class Solution {
public:
int majorityElement(vector<int>& nums) {
    int candidate = nums[0], counter = 0;
    for (int n: nums) {
        if (counter == 0) {
            candidate = n;
            counter = 1;
        } else if (candidate == n) {
            counter++;
        } else {
            counter--;
        }
    }
    return candidate;
}
};




// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         map<int,int>mp;
//         int m=0;
//         if(nums.size()%2==0)
//             m=nums.size()/2;
//         else
//             m=(nums.size()+1)/2;
        
//         for(int i=0;i<nums.size();i++)
//         {
//             mp[nums[i]]++;
//             if(mp[nums[i]]>=m) 
//                 return nums[i];
//         }
//         return 0;
        
        
//     }
// };