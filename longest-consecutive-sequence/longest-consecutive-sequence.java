class Solution {
    public int longestConsecutive(int[] nums) {
        if(nums.length==0)
            return 0;
        Arrays.sort(nums);
        int ans=1,temp=1;
        for(int i=1;i<nums.length;i++){
            if(nums[i]!=nums[i-1]){
               if(nums[i]==nums[i-1]+1)
                temp+=1;
            
                else{
                    ans=Math.max(temp,ans);
                    temp=1;
                }
            }
        }
        return Math.max(ans,temp);
    }
}