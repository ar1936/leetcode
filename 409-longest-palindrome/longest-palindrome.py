class Solution:
    def longestPalindrome(self, s: str) -> int:
        mp = defaultdict(int)
        even_sum = 0
        sum_odd = 0
        for c in s:
            mp[c]+=1
        flag_odd = False
        for k in mp.keys():
            if mp[k]%2==1:
                flag_odd = True
                sum_odd+=(mp[k]-1)
            else:
                even_sum+=mp[k]
        if flag_odd:
            sum_odd+=1
        return even_sum+sum_odd
