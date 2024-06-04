# class Solution:
#     def longestPalindrome(self, s: str) -> int:
#         mp = defaultdict(int)
#         even_sum = 0
#         sum_odd = 0
#         for c in s:
#             mp[c]+=1
#         for k in mp.keys():
#             if mp[k]%2==1:
#                 sum_odd+=(mp[k]-1)
#             else:
#                 even_sum+=mp[k]
#         if sum_odd>0:
#             sum_odd+=1
#         return even_sum+sum_odd


#         from collections import defaultdict

class Solution:
    def longestPalindrome(self, s: str) -> int:
        mp = defaultdict(int)
        for c in s:
            mp[c] += 1
        
        even_sum = 0
        sum_odd = 0
        
        for count in mp.values():
            if count % 2 == 0:
                even_sum += count
            else:
                even_sum += count - 1
                sum_odd = 1  # At least one odd count allows for a center character
        
        return even_sum + sum_odd
