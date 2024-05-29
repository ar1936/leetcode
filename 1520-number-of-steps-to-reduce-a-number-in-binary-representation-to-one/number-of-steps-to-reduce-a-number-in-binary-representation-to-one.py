class Solution:
    def numSteps(self, s: str) -> int:
        ans = 0
        while len(s)>1:
            if s[-1] == '1':
                j = len(s)-1
                while(j>=0 and s[j]=='1'):
                    s = s[:j] + '0' + s[j+1:]
                    j-=1
                if j<0:
                    s = '1' + s[:]
                else:
                    s = s[0:j] + '1' + s[j+1:]
            else:
                s = s[:-1]
            ans +=1
        return ans


