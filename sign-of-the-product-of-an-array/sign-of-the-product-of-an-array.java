class Solution {
    public int arraySign(int[] nums) {
        int count_zero=0,count_negative=0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]==0){
                count_zero++;
            }
            else if(nums[i]<0){
                count_negative++;
            }           
            if(count_zero>0){
                return 0;
            }
        }
        return (count_negative%2==0?1:-1);
        
    }
}