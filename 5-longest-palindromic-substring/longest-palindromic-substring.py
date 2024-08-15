class Solution:
    def longestPalindrome(self, s: str) -> str:
        ans = s[0]
        n = len(s)
        for k in range(n):
            i = k-1
            j = k+1
            while i>=0 and j<n and s[i]==s[j]:
                if len(ans)<len(s[i:j+1]):
                    ans = s[i:j+1]
                i-=1
                j+=1
            i = k
            j = k+1
            while i>=0 and j<n and s[i]==s[j]:
                if len(ans)<len(s[i:j+1]):
                    ans = s[i:j+1]
                i-=1
                j+=1
        return ans