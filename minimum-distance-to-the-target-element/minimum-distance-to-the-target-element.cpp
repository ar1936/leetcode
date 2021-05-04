class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        // int i=0;
        // for(;i<nums.size();i++){
        //     if(nums[i]==target)
        //         break;
        // }
        // return min(abs(start-i),i);
        
        int nums_len = nums.size();
    
    int index = -1;
    for(int i = 0; i < nums_len; i++){
        if(nums[i] == target){
            if(index == -1){
                //cout << "Index is changed" << endl;
                index = abs(i-start);
            }
            else
                index = min(index, abs(i-start));
        }
    }
    return index;
    }
};
    


