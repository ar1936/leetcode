# class Solution:
#     def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
#         ans = []
#         mp = defaultdict(list)
#         visited = defaultdict(bool)
#         for ind, (node1,node2) in enumerate(equations):
#             mp[node1].append([node2,values[ind]])
#             if values[ind]!=0.0:
#                 mp[node2].append([node1,1/values[ind]])
#             visited[node1] = False
#             visited[node2] = False
#         for (start_node,end_node) in queries:
#             if start_node==end_node:
#                 ans.append(1.0)
#                 continue
#             if start_node not in visited or end_node not in visited:
#                 ans.append(-1.0)
#                 continue
#             for key in visited.keys():
#                 visited[key] = False        
#             q = []
#             q.append(start_node)
#             val = 1.0
#             while q:
#                 prev_node = q.pop()
#                 visited[prev_node] = True
#                 if prev_node == end_node:
#                     ans.append(val)
#                     break
#                 for (next_node,value) in mp[prev_node]:
#                     if visited[next_node] == False:
#                         visited[next_node] = True
#                         q.append(next_node)
#                         val*=value
#         return ans



class Solution:
    def calcEquation(self, equations, values, queries):
        ans = []
        mp = defaultdict(list)
        visited = defaultdict(bool)

        # Building the graph
        for ind, (node1, node2) in enumerate(equations):
            mp[node1].append([node2, values[ind]])
            if values[ind] != 0.0:
                mp[node2].append([node1, 1 / values[ind]])
            visited[node1] = False
            visited[node2] = False

        # Processing each query
        for (start_node, end_node) in queries:
            if start_node == end_node:
                if start_node in visited:
                    ans.append(1.0)
                else:
                    ans.append(-1.0)
                continue

            if start_node not in visited or end_node not in visited:
                ans.append(-1.0)
                continue

            for key in visited.keys():
                visited[key] = False        

            q = deque([(start_node, 1.0)])
            found = False

            while q and not found:
                prev_node, val = q.popleft()
                visited[prev_node] = True

                for (next_node, value) in mp[prev_node]:
                    if not visited[next_node]:
                        if next_node == end_node:
                            ans.append(val * value)
                            found = True
                            break
                        q.append((next_node, val * value))
                        visited[next_node] = True

            if not found:
                ans.append(-1.0)
                
        return ans