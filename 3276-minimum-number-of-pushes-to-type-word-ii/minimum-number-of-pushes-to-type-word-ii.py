class Solution:
    def minimumPushes(self, word: str) -> int:
        mp = defaultdict(int)
        for s in word:
            mp[s] += 1
        if len(mp)<=8:
            return len(word)
        # can we optimise this and solve it without sorting ??? yes 
        ans = 0
        for i, v in enumerate(sorted(mp.values(), reverse = True)):
            if (i + 1)<=8:
                ans+=v
            elif (i + 1)<=16:
                ans+= 2*v
            elif (i + 1)<=24:
                ans+= 3*v
            else:
                ans+= 4*v
        return ans