from sortedcontainers import SortedDict
class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        mp = SortedDict()
        for l1,l2 in intervals:
            if l1 not in mp:
                mp[l1] = 0
            if l2 not in mp:
                mp[l2] = 0
            mp[l1] += 1
            mp[l2] -= 1
        ans = 0 
        sum = 0
        for k in mp:
            sum+=mp[k]
            ans = max(ans,sum)
        return  ans