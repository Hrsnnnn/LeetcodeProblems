from typing import List

class Solution:
    def buildGraph(self, n, edges) -> dict:
        graph = {}
        for i in range(n):
            graph.update({i:[]})
        for e in edges:
            start, end = e[0]-1, e[1]-1
            graph[start].append(end)
            graph[end].append(start)

        return graph

    def coloring(self, n:int, c:bool, visited:set, dislikes:List[List[int]], colors:dict):
        # print(n, c, visited, colors)
        if n in visited:
            if colors[n] != c:
                return False, visited
            else:
                return True, visited
        
        colors[n] = c
        neighbors = dislikes[n]
        visited.add(n)

        for n in neighbors:
            res, visited = self.coloring(n, not c, visited, dislikes, colors)
            if not res:
                return False, visited
        return True, visited

    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        if n == 1:
            return True
        graph = self.buildGraph(n, dislikes)
        arr = set([i for i in range(n)])
        allvisited = set()

        while len(allvisited) != n:
            notvisited = arr - allvisited
            point = list(notvisited)[0]
            res, visited = self.coloring(point, True, set(), graph, {})
            # print('allvisited:', allvisited, visited, 'before')
            allvisited = allvisited.union(visited)
            # print('allvisited:', allvisited, visited)
        
        return res

if __name__ == '__main__':
    a = ({1, 2, 3, 4, 5})
    s = set({7, 8})
    print(a.union(s))
    print(a, s)
    sol = Solution()
    a = sol.possibleBipartition(10, [[6,9],[1,3],[4,8],[5,6],[2,8],[4,7],[8,9],[2,5],[5,8],[1,2],[6,7],[3,10],[8,10],[1,5],[3,6],[1,10],[7,9],[4,10],[7,10],[1,4],[9,10],[4,6],[2,7],[6,8],[5,7],[3,8],[1,8],[1,7],[7,8],[2,4]])
    print(a)
