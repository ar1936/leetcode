class Solution {
    public int[] getMaximumXor(int[] nums, int maximumBit) {
        int n=nums.length,XOR=0;
        for(int i=0;i<n;i++){
            XOR^=nums[i];
        }
        int ans[]=new int[n] ;
        ans[0]=(XOR^=(1<<maximumBit)-1);
        for(int i=1;i<n;i++){
            ans[i]=XOR^=nums[n-i];
        }
        return ans;
    }
}