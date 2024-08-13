class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        mp = collections.defaultdict(int)
        for i in range(len(wall)):
            s = 0
            for j in range(len(wall[i])-1):
                s+= wall[i][j]
                mp[s]+=1
        return len(wall) - max(list(mp.values()) + [0])