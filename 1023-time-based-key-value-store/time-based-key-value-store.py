class TimeMap:

    def __init__(self):
        self.mp1 = defaultdict(list)
        self.mp2 = defaultdict(str)

    def binary_search(self,arr,target):
        l = 0
        r = len(arr) - 1
        best_match = None  # This will store the best match that is less than or equal to the target

        while l <= r:
            mid = l + (r - l) // 2
            if arr[mid] == target:
                return arr[mid]
            elif arr[mid] < target:
                best_match = arr[mid]  # Update best match to the current mid value
                l = mid + 1  # Continue searching in the right half
            else:
                r = mid - 1  # Continue searching in the left half

        return best_match

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.mp1[key].append(timestamp)
        self.mp2[timestamp] = value

    def get(self, key: str, timestamp: int) -> str:
        arr = self.mp1[key]
        val = self.binary_search(arr,timestamp)
        return self.mp2[val]


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)