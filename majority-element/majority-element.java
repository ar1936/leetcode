class Solution {
    public int majorityElement(int[] nums) {
        int count=0;
        Integer ans=null;
        for(int num:nums){
            if(count==0){
                ans=num;
            }
            count+=(ans==num?1:-1);
        }
        return ans;
    }
}