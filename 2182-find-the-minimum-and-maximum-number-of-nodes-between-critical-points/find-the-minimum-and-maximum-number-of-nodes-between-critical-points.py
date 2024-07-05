class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        critical_point = []
        prev_val = head.val 
        head = head.next
        cnt = 1
        while head.next:
            val = head.val 
            next_val = head.next.val
            if (val > prev_val and val > next_val) or (val < prev_val and val < next_val):
                critical_point.append(cnt)
            prev_val = head.val
            cnt+=1
            head = head.next
        if len(critical_point)<2:
            return [-1,-1]
        mn = 100000
        mx = critical_point[-1] - critical_point[0]
        for i in range(1,len(critical_point)):
            mn = min(mn, critical_point[i]-critical_point[i-1])
        return [mn,mx]