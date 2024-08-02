class Solution:
    def minSwaps(self, data: List[int]) -> int:
        gap = sum(data)
        tmp = sum(data[:gap])
        ans = gap - tmp 
        print(tmp)
        for i in range(gap,len(data)):
            tmp -= data[i-gap]
            tmp += data[i]
            ans = min(gap-tmp, ans)
        return ans