class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        ans = []
        mp = defaultdict(int)
        for s in arr:
            mp[s]+=1
        for s in arr:
            if mp[s] == 1:
                ans.append(s)
        return ans[k-1] if len(ans)>=k else ""