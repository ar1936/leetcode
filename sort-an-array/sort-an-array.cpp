class Solution {

    
    void merge(vector<int>& nums, int l, int m, int r){
        vector<int> tmp(r - l + 1);
        int i = l; // index for left subarray
        int j = m + 1; // index for right subarray
        int k = 0; // index for temporary array
        while(i <= m && j <= r){
            if(nums[i] <= nums[j]) tmp[k++] = nums[i++]; 
            else tmp[k++] = nums[j++];
        }
        while(i <= m) tmp[k++] = nums[i++];
        while(j <= r) tmp[k++] = nums[j++]; 
        for(i = 0; i < k; i++) nums[l + i] = tmp[i];
    }
	
    void merge_sort(vector<int>&v,int l,int r){
        if(l<r){
        int mid=l+(r-l)/2;
        merge_sort(v,l,mid);
        merge_sort(v,mid+1,r);
        merge(v,l,mid,r);
        }
    }
    
public:
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums,0,nums.size()-1);
        return nums;
    }
};

