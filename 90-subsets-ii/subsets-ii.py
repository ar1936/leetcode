class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)
        def subset(ind, tmp_subset_arr ,subset_arr):
             
            if ind == len(nums):
                subset_arr.append(tuple(tmp_subset_arr.copy()))
                return
            tmp_subset_arr.append(nums[ind])
            subset(ind+1,tmp_subset_arr,subset_arr)
            tmp_subset_arr.pop()
            subset(ind+1,tmp_subset_arr,subset_arr)
            

        
        subset_arr = []
        subset(0,[],subset_arr)
        return list(map(list,set(subset_arr)))

