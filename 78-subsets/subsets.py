class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        def solve(ind,ans,temp):
            if ind==len(nums):
                ans.append(temp.copy())
                return 
            temp.append(nums[ind])
            solve(ind+1,ans,temp)
            temp.pop()
            solve(ind+1,ans,temp)
            
        ans = []
        solve(0,ans,[])
        return ans