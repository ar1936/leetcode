# https://platform.openai.com/playground/p/uNVtv9zb9QfUJd1G8dchsxCM?mode=chat

class Solution:
    # def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
    #     candidates.sort()
    #     arr = []
    #     ans = []
    #     def solve(ind, sum, is_prev_selected) -> None:
    #         if(sum==target):
    #             ans.append(tuple(arr))
    #             return 
    #         if(ind == len(candidates) or sum>target):
    #             return 
    #         if(ind>0 and candidates[ind]==candidates[ind-1] and not is_prev_selected):
    #             solve(ind+1,sum,False)
    #         else:
    #             arr.append(candidates[ind])
    #             solve(ind+1,sum+candidates[ind],True)
    #             arr.pop()
    #             solve(ind+1,sum,False)
    #     solve(0,0,False)
    #     return list(map(list,set(ans)))


    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()  # Sort the candidates to handle duplicates
        ans = []
        
        def backtrack(start, combination, total):
            if total == target:
                ans.append(list(combination))  # Add a copy of the combination
                return
            if total > target:
                return  # Stop if the sum exceeds the target
            
            for i in range(start, len(candidates)):
                # Skip duplicates
                if i > start and candidates[i] == candidates[i - 1]:
                    continue
                # Include the candidate and move to the next
                combination.append(candidates[i])
                backtrack(i + 1, combination, total + candidates[i])
                # Exclude the candidate and move to the next
                combination.pop()
        
        backtrack(0, [], 0)
        return ans