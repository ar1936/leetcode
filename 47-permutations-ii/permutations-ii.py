class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        def permutation(ind,permutation_arr):
            if ind == len(nums):
                permutation_arr.append(tuple(nums.copy()))
                return 
            for i in range(ind,len(nums)):
                nums[i] , nums[ind] = nums[ind], nums[i]
                permutation(ind+1,permutation_arr)
                nums[i] , nums[ind] = nums[ind], nums[i]
                
        permutation_arr = []
        permutation(0,permutation_arr)
        return list(map(list,set(permutation_arr)))