class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand)%groupSize != 0:
            return False
        mp = defaultdict(int)
        hand = sorted(hand)
        for h in hand:
            mp[h]+=1
        count = 0
        for h in hand:
            cnt = 0
            arr = []
            for i in range(groupSize):
                if h+i in mp:
                    cnt+=1
                else:
                    break
            if cnt == groupSize:
                for i in range(groupSize):
                    if mp[h+i]>0:
                        mp[h+i]-=1
                    if mp[h+i] == 0:
                        del mp[h+i]
                count+=1
        return count==(len(hand)//groupSize)
