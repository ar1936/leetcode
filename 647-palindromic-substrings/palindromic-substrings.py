class Solution:
    def countSubstrings(self, s: str) -> int:
        # n = len(s1)
        # s2 = s1
        # def solve(x, y):
        #     print(x,y)
        #     # if x==n and y==n:
        #     #     return 0
        #     if x>y:
        #         return 0
        #     if x == n or y == n:
        #         return 0
        #     if x == y:
        #         return 1
        #     if s1[x] == s2[y]:
        #         return solve(x+1,y) + solve(x,y+1)
        #     else:
        #         return solve(x+1,y+1)
            
        # return solve(0,0)
        ans = 0
        final_ans = ""
        for i in range(len(s)):
            left = i - 1
            right = i + 1
            ans+=1
            while(left>=0 and right < len(s) and s[left] == s[right]):
                ans+=1
                left -= 1
                right +=1
            left = i
            right = i + 1
            while(left>=0 and right < len(s) and s[left] == s[right]):
                ans+=1
                left -= 1
                right +=1
        return ans