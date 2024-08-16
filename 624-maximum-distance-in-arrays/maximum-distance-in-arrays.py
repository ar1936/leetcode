class Solution(object):
    def maxDistance(self, arrays):
        """
        :type arrays: List[List[int]]
        :rtype: int
        """
        m = len(arrays)
        MAX, max_i = max([(arrays[i][-1], i) for i in range(m)])
        MIN, min_i = min([(arrays[i][0], i) for i in range(m)])
        a = max(abs(arrays[i][0] - MAX) for i in range(m) if i != max_i)
        b = max(abs(arrays[i][-1] - MIN) for i in range(m) if i != min_i)
        return max(a, b)