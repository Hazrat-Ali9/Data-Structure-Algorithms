class Graph:

    def __init__(self, n: int, edges: List[List[int]]):
        self.adj = [[] for _ in range(n)]
        for fromNode, toNode, cost in edges:
            self.adj[fromNode].append((toNode, cost))

    def addEdge(self, edge: List[int]) -> None:
        fromNode, toNode, cost = edge
        self.adj[fromNode].append((toNode, cost))

    def shortestPath(self, node1: int, node2: int) -> int:
        n = len(self.adj)
        pq = [(0, node1)]
        costForNode = [inf] * (n)
        costForNode[node1] = 0
        while pq:
            currCost, currNode = heappop(pq)
            if currCost > costForNode[currNode]: continue
            if currNode == node2: return currCost
            for nei, cost in self.adj[currNode]:
                newCost = currCost + cost
                if newCost < costForNode[nei]:
                    costForNode[nei] = newCost
                    heappush(pq, (newCost, nei))
        return -1


# Your Graph object will be instantiated and called as such:
# obj = Graph(n, edges)
# obj.addEdge(edge)
# param_2 = obj.shortestPath(node1,node2)