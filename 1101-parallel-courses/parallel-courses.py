class Solution:
    def minimumSemesters(self, n: int, relations: List[List[int]]) -> int:
        indegree = [0]*n
        mp = defaultdict(list)
        for r1,r2 in relations:
            mp[r1-1].append(r2-1)
            indegree[r2-1]+=1
        q = deque()
        for i in range(n):
            if indegree[i] == 0:
                q.append(i)
        cnt = 0
        ans = 0
        while q:
            for _ in range(len(q)):
                prev_node = q.popleft()
                cnt += 1
                for curr_node in mp[prev_node]:
                    indegree[curr_node]-=1
                    if indegree[curr_node] == 0:
                        q.append(curr_node)
            ans+=1
            if cnt==n:
                return ans
        return -1