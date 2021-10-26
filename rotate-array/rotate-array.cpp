class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = (nums.size()-1-k+nums.size())%nums.size();
        
        vector<int>temp=nums;
        for(int i=0;i<nums.size();i++){
            nums[i]=temp[(i+k+1)%nums.size()];
        }
    }
};



// 1 2 3 4 5 6 7
// 0 1 2 3 4 5 6 

    
// 5 6 7 1 2 3 4 
// (i+k)%v,size();