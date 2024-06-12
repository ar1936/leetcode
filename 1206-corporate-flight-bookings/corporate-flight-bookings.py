class Solution:
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        arr = [0]*(n+1)
        for b in bookings:
            arr[b[0]-1]+=b[2]
            arr[b[1]]-=b[2]
        for i in range(1,n):
            arr[i]+=arr[i-1]
        return arr[:-1]