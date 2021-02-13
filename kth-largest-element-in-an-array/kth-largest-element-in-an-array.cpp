class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       return partition(nums,0,nums.size()-1,nums.size()-k+1);//convert to (size-k+1)th smallest problem.
       
    }

    int partition(vector<int>&nums,int left,int right,int k){// k denote the kth smallest in the nums
        int i=left,j=right,x=nums[left];
        while(i<j){
            while(i<j&&nums[j]>=x)j--;
            nums[i]=nums[j];
            while(i<j&&nums[i]<x)i++;
            nums[j]=nums[i];
        }
        nums[i]=x;
        if(i==k-1) return nums[i];
        else if(i>k-1) return partition(nums,left,i-1,k);
        else return partition(nums,i+1,right,k);
    }
};
