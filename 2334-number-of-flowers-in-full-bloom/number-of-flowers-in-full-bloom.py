class Solution:
    def fullBloomFlowers(self, flowers: List[List[int]], people: List[int]) -> List[int]:
        mp = defaultdict(int)
        for (start,end) in flowers:
            mp[start]+=1
            mp[end+1]-=1
        position = sorted(mp.keys())
        pre_sum = []
        sum = 0
        for p in position:
            sum += mp[p]
            pre_sum.append(sum)
        ans = []
        for p in people:
            ind = bisect_right(position,p)-1
            ans.append(pre_sum[ind])
        return ans