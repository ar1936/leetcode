class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        mp = defaultdict(int)
        for t in trips:
            mp[t[1]] +=  t[0]
            mp[t[2]] -=  t[0]
        sum = 0
        for k in sorted(mp):
            sum+=mp[k]
            if capacity<sum:
                return False
        return True