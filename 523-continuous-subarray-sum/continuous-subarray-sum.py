class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        mp = defaultdict(int)
        sum = 0
        for ind, num in enumerate(nums):
            sum = (sum+num)%k
            if sum==0 and ind>=1:
                return True
            if sum in mp:
                if ind-mp[sum]>1:
                    return True
            else:
                mp[sum] = ind

        return False