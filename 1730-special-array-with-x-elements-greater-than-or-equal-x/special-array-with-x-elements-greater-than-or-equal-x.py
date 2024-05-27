class Solution:
    def specialArray(self, nums: List[int]) -> int:
        def solve(mid):
            count = 0
            for num in nums:
                if num>=mid:
                    count+=1
            return count

        low = 0
        high = 1001
        while(low<=high):
            mid = low+(high-low)//2
            cnt = solve(mid)
            if cnt==mid:
                return mid
            elif cnt>mid:
                low = mid+1
            else:
                high = mid-1
        return -1
