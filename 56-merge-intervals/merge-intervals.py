class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        mp = defaultdict(int)
        for interval in intervals:
            mp[interval[0]] += 1
            mp[interval[1]] -= 1
        mp_key = sorted(mp.keys())
        prefix_sum = 0
        ans = []
        tmp_interval = []
        for k in mp_key:
            if prefix_sum == 0:
                tmp_interval.append(k)
            prefix_sum += mp[k]
            mp[k] = prefix_sum
            if mp[k] == 0:
                tmp_interval.append(k)
                ans.append(tmp_interval)
                tmp_interval = []
        return ans