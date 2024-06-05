class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        ans = []
        mp = defaultdict(list)
        for i in range(len(words)):
            tmp = [0]*26
            for j in range(len(words[i])):
                tmp[ord(words[i][j]) - ord('a')]+=1
            mp[i].append(tmp)
        for m in range(26):
            mn = 100000
            for k in mp.keys():
                mn = min(mn,mp[k][0][m])
            ans.extend(chr(m+ord('a'))*mn)
        return ans