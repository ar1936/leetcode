class Solution {
    public int jump(int[] array) {

        if(array.length == 0 || array.length == 1) {
            return 0;
        }
        int ans=0,max_jumps=0,curr_jumps=0;
        
        for(int i=0;i<array.length-1;i++){
            
            max_jumps=Math.max(max_jumps,i+array[i]);
            // for(int j=1;j<=max_jumps;j++){
            //     curr_jumps=nums[j];
            //     if(solve())
            //     ans=min(ans,solve(nums,curr_jumps));
            // }
            if(curr_jumps==i)
            {
                ans++;
                curr_jumps=max_jumps;
            }
            
        }
        return ans;
    }
}



