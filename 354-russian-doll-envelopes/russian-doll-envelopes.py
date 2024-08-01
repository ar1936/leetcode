class Solution:
    def maxEnvelopes(self, e: List[List[int]]) -> int:
        e.sort(key=lambda x: (x[0], -x[1]))
        dp = []
        for num1, num2 in e:
            i = bisect_left(dp,num2)
            if i == len(dp):
                dp.append(num2)
            else:
                dp[i] = num2
        return len(dp)