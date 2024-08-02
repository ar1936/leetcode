class Solution:
    def numKLenSubstrNoRepeats(self, s: str, k: int) -> int:
        ans = 0
        mp = defaultdict(int)
        for i in range(len(s)):
            c = ord(s[i]) - 97
            if i<k:
                mp[c] += 1
            else:
                mp[c] += 1
                mp[ord(s[i-k]) - 97]-=1
                if mp[ord(s[i-k]) - 97] == 0:
                    del mp[ord(s[i-k]) - 97]
            if len(mp) == k:
                ans+=1
        return ans