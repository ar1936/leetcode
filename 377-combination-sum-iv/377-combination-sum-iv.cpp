class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        vector<unsigned long long int>arr(target+1,0);
        arr[0] = 1;
        for(int i = 1;i<=target;i++)
        {
            for(auto j:nums)
            {
                if(i>=j)
                    arr[i] += arr[i-j];
            }
        }
        return arr[target];
    }
};