class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        mp = defaultdict(int)
        for word in words:
            mp[word]+=1
        ans = 0 
        for word in mp:
            i = 0
            j = 0
            while i<len(s) and j<len(word):
                if s[i] == word[j]:
                    i+=1
                    j+=1
                else:
                    i+=1
            if j == len(word):
                ans+=mp[word]
        return ans