
class SegmentTree:
    def __init__(self, size):
        self.size = size
        self.tree = [0] * (2 * size)
    
    def update(self, index, value):
        # Shift the index to the leaf
        index += self.size
        # Update from leaf to root
        while index > 0:
            self.tree[index] += value
            index //= 2
    
    def query(self, left, right):
        # Return sum of [left, right)
        result = 0
        left += self.size
        right += self.size
        while left < right:
            if left % 2 == 1:
                result += self.tree[left]
                left += 1
            if right % 2 == 1:
                right -= 1
                result += self.tree[right]
            left //= 2
            right //= 2
        return result

class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        if not nums:
            return []
        
        # Find the range of values
        min_val = min(nums)
        max_val = max(nums)
        range_size = max_val - min_val + 1
        
        # Initialize segment tree with appropriate size
        segment_tree = SegmentTree(range_size)
        result = []
        
        # Process each number in reverse
        for num in reversed(nums):
            # Calculate the index for the current number
            index = num - min_val
            # Query the number of elements smaller than the current number
            smaller_count = segment_tree.query(0, index)
            result.append(smaller_count)
            # Update the segment tree to include the current number
            segment_tree.update(index, 1)
        
        return list(reversed(result))
