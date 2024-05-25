class Solution:
    def wordBreak(self, s: str, words: List[str]) -> List[str]:
        def solve(ind,tmp_str,st,ans):
            # print(tmp_str,st)
            if s==st:
                ans.append(' '.join(tmp_str))
                return 
            if s[:len(st)]!=st:
                return 
            if len(st)>=len(s):
                return 
            if ind>=len(words):
                return 
            tmp_str.append(words[ind])
            st += words[ind]
            solve(0,tmp_str,st,ans)
            st = st[:-len(tmp_str[-1])]
            tmp_str.pop()
            solve(ind+1,tmp_str,st,ans)   

        ans = []
        solve(0,[],"",ans)
        return ans