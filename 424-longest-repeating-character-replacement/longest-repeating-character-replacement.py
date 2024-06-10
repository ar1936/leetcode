class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        mp = defaultdict(int)
        start = 0
        ans = 0
        for end in range(len(s)):
            mp[s[end]]+=1
            mx = max(mp.values())
            while (end-start+1) > k + mx:
                mp[s[start]]-=1
                mx = max(mp.values())
                if mp[s[start]] == 0:
                    del mp[s[start]] 
                start+=1
            ans = max(ans,end-start+1)     
        return ans