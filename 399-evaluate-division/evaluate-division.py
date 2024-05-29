class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        ans = []
        mp = defaultdict(list)
        visited = defaultdict(bool)
        for ind, (node1,node2) in enumerate(equations):
            mp[node1].append([node2,values[ind]])
            if values[ind]!=0.0:
                mp[node2].append([node1,1/values[ind]])
            visited[node1] = False
            visited[node2] = False
        for (start,end) in queries:
            if start == end:
                if start in mp:
                    ans.append(1.0)
                else:
                    ans.append(-1.0)
                continue
            if start not in mp or end not in mp:
                ans.append(-1.0)
                continue
            for key in visited:
                visited[key] = False
            q = deque()
            q.append((start,1.0))
            found = False
            while q and found == False:
                prev_node, val = q.popleft()
                visited[prev_node] = True
                for (next_node,value) in mp[prev_node]:
                    if visited[next_node]==False:
                        q.append((next_node,val*value))
                        if next_node == end:
                            found = True
                            ans.append(val*value)
            if found == False:
                ans.append(-1.0)
        return ans