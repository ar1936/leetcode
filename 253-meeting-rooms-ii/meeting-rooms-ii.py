class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        if len(intervals) == 0:
            return 0
        free_room = []
        intervals = sorted(intervals, key = lambda x:x[0])
        heapq.heappush(free_room, intervals[0][1])

        for i in intervals[1:]:
            if free_room[0]<=i[0]:
                heapq.heappop(free_room)
            heapq.heappush(free_room, i[1])

        return len(free_room)