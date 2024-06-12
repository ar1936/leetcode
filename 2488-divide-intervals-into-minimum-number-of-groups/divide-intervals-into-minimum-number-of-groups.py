class Solution:
    def minGroups(self, intervals: List[List[int]]) -> int:
        ans = 0
        mp = defaultdict(int)
        for i in intervals:
            mp[i[0]]+=1
            mp[i[1]+1]-=1
        sum = 0
        for k in sorted(mp):
            sum += mp[k]
            ans = max(ans,sum)
        return ans