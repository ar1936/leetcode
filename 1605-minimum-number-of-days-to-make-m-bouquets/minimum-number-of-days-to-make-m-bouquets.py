class Solution:
    def minDays(self, nums: List[int], m: int, k: int) -> int:
        def solve(mid):
            count = 0
            count_k = 0
            for i in range(len(nums)):
                if nums[i]<=mid:
                    count+=1
                    if count == k:
                        count = 0
                        count_k += 1
                else:
                    count = 0    
            return count_k>=m
        lo = min(nums)
        hi = max(nums)
        ans = -1
        while lo<=hi:
            mid = lo+(hi-lo)//2
            if solve(mid):
                ans = mid
                hi = mid - 1
            else:
                lo = mid + 1
        return ans 
# if(solve(mid)){
#             ans=mid;
#             r=mid-1;
#         }
#         else{
#             l=mid+1;
#         }