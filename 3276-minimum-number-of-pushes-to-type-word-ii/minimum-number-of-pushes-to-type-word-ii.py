class Solution:
    def minimumPushes(self, word: str) -> int:
        mp = defaultdict(int)
        arr = []
        for s in word:
            mp[s] += 1
        for k in mp:
            arr.append(mp[k])
        if len(arr)<=8:
            return len(word)
        arr = sorted(arr, reverse = True)
        ans = 0
        cnt = 0
        for i in range(len(arr)):
            cnt = i+1
            if cnt<=8:
                ans+=arr[i]
            elif cnt<=16:
                ans+= 2*arr[i]
            elif cnt<=24:
                ans+= 3*arr[i]
            else:
                ans+= 4*arr[i]
        return ans