class Solution:
   def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
      
       nums.sort()
       ans = []
       arr = []
       def solve(ind:int, is_prev_selected:bool) -> None:
           if(ind == len(nums)):
               ans.append(tuple(arr))
               return None
           if ind>0 and nums[ind] == nums[ind-1] and not is_prev_selected:
               solve(ind+1,False)
           else:
               arr.append(nums[ind])
               solve(ind+1,True)
               arr.pop()
               solve(ind+1,False)
       solve(0,False)
       return ans