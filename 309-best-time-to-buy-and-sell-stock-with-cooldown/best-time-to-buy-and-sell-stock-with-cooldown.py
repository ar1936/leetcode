class Solution:
    def maxProfit(self, nums: List[int]) -> int:
        mp = {}
        def solve(ind,price,is_sell):
            if ind >= len(nums):
                return 0
            if (ind,price,is_sell) in mp:
                return mp[(ind,price,is_sell)]
            if is_sell and (nums[ind]-price)>0: 
                mp[(ind,price,is_sell)] = max(solve(ind+2,0,False)+(nums[ind]-price), solve(ind+1,price,is_sell))
            else:
                mp[(ind,price,is_sell)] =  solve(ind+1,nums[ind],True)
            return mp[(ind,price,is_sell)]
        return solve(0,0,False)


# class Solution:
#     def maxProfit(self, nums: List[int]) -> int:
#         memo = {}

#         def solve(ind, price, is_sell):
#             if ind >= len(nums):
#                 return 0
#             if (ind, price, is_sell) in memo:
#                 return memo[(ind, price, is_sell)]

#             if is_sell and (nums[ind] - price) > 0:
#                 memo[(ind, price, is_sell)] = max(solve(ind + 2, 0, False) + (nums[ind] - price), solve(ind + 1, price, is_sell))
#             else:
#                 memo[(ind, price, is_sell)] = solve(ind + 1, nums[ind], True)
            
#             # memo[(ind, price, is_sell)] = result
#             return memo[(ind, price, is_sell)]

#         return solve(0, 0, False)