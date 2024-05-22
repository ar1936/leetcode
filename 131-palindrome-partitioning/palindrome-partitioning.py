class Solution:
    def partition(self, s: str) -> List[List[str]]:
        def is_palindrome(s):
            i = 0
            j = len(s)-1
            while(i<j):
                if s[i] != s[j]:
                    return False
                i+=1
                j-=1
            return True
        def solve(ind,tmp,ans):
            if ind == len(s):
                ans.append(tmp.copy())
                return 
            for i in range(ind,len(s)):
                if(is_palindrome(s[ind:i+1])):
                    tmp.append(s[ind:i+1])
                    solve(i+1,tmp,ans)
                    tmp.pop()
        
        ans = []
        solve(0,[],ans)
        return ans