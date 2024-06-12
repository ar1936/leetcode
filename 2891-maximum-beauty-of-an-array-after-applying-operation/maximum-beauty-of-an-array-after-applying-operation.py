class Solution:
    def maximumBeauty(self, nums: List[int], k: int) -> int:
        mp = defaultdict(int)
        ans = 0
        for n in nums:
            mp[n+k+1]-=1
            mp[n-k]+=1
        sum = 0
        for k in sorted(mp):
            sum+=mp[k]
            ans = max(sum,ans) 
        return ans