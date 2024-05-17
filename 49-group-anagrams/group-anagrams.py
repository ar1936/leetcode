class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mp = {}
        ans = []
        for s in strs:
            count = [0]*26
            for chr in s:
                count[ord(chr)-ord('a')]+=1
            if tuple(count) not in mp:
                mp[tuple(count)] = [s]
            else:
                mp[tuple(count)].append(s)
            
        for val in mp.keys():
            ans.append(mp[val])
        return ans
