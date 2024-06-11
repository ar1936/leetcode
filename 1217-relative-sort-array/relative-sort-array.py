class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        ans = []
        mp = defaultdict(int)
        for v in arr1:
            mp[v]+=1
        for v in arr2:
            ans.extend([v]*mp[v])
            del mp[v]
        rem = []
        for k in mp.keys():
            for _ in range(mp[k]):
                rem.append(k)
        ans.extend(sorted(rem))
        return ans