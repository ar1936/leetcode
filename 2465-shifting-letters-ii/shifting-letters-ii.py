class Solution:
    def shiftingLetters(self, s: str, shifts: List[List[int]]) -> str:
        mp = defaultdict(int)
        for sh in shifts:
            if sh[2] == 1:
                mp[sh[0]]+=1
                mp[sh[1]+1]-=1
            else:
                mp[sh[0]]-=1
                mp[sh[1]+1]+=1
        ans = []
        sum = 0
        for i in range(len(s)):
            sum+=mp[i]
            c = chr((ord(s[i]) - 97 + sum)%26 + 97) 
            ans.append(c)
        return ''.join(ans)
