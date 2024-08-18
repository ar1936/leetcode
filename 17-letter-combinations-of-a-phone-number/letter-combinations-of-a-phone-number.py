class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        dic = { "2": "abc", "3": "def", "4":"ghi", "5":"jkl", "6":"mno", "7":"pqrs", "8":"tuv", "9":"wxyz"}
        ans = []

        def solve(ind,s):
            if ind == len(digits):
                ans.append(str(s))
                return 
            for c in dic[digits[ind]]:
                solve(ind+1,s + str(c))
        if len(digits)==0:
            return ans
        solve(0,"")
        return ans 