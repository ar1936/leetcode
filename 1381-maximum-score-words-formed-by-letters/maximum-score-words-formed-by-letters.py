class Solution:
    def maxScoreWords(self, words: List[str], letters: List[str], score: List[int]) -> int:
        def solve(ind,tmp,ans):
            if ind == len(words):
                ans.append(tmp.copy())
                return 
            tmp.append(words[ind])
            solve(ind+1,tmp,ans)
            tmp.pop()
            solve(ind+1,tmp,ans)
        ans = []
        solve(0,[],ans)
        mp = defaultdict(int)
        for c in letters:
            mp[c]+=1
        final_ans = 0
        for subset in ans:
            tmp = 0
            mp1 = defaultdict(int)
            for word in subset:
                flag = False
                for i in range(len(word)):
                    mp1[word[i]]+=1
                    tmp+=score[ord(word[i])-ord('a')]
                    if mp1[word[i]]>mp[word[i]]:
                        flag = True
                if flag:
                    break
                else:
                    final_ans = max(final_ans,tmp)
        return final_ans