class Solution:
    def findItinerary(self, t: List[List[str]]) -> List[str]:
        graph = defaultdict(list)
        for t1, t2 in t:
            graph[t1].append(t2)
        for k in graph:
            graph[k] = sorted(graph[k], reverse = True)
        ans = []
        def dfs(origin):
            destList = graph[origin]
            while destList:
                #while we visit the edge, we trim it off from graph.
                nextDest = destList.pop()
                dfs(nextDest)
            ans.append(origin)
                       
        dfs("JFK")
        return ans[::-1]