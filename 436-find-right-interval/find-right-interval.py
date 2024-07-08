
class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        from sortedcontainers import SortedDict
        mp = SortedDict()
        for i in range(len(intervals)):
            mp[intervals[i][0]] = i
        ans = []
        for l1,l2 in intervals:
            lower_bound = mp.bisect_left(l2)
            if lower_bound == len(mp):
                ans.append(-1)
            else:
                ans.append(mp.peekitem(lower_bound)[1])
        return ans