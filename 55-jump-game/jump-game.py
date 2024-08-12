class Solution:
    def canJump(self, nums: List[int]) -> bool:
        max_rechable_ind = 0
        for i in range(len(nums)):
            if i>max_rechable_ind:
                return False
            max_rechable_ind = max(max_rechable_ind, i+nums[i])
            if max_rechable_ind>=len(nums)-1:
                return True
            
        return False