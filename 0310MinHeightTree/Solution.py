from typing import List, Tuple

class Solution:
    def buildTree(self, n, edges) -> dict:
        graph = {}
        for i in range(n):
            graph.update({i:[]})
        for e in edges:
            start, end = e[0], e[1]
            graph[start].append(end)
            graph[end].append(start)

        return graph
    
    def maxHeight(self, start, graph:dict, closed:set):
        nxt = graph[start]
        print(closed, start, nxt)
        if len(nxt) == 0:
            return 0
        elif len(graph) == len(closed):
            return 0
        else:
            height = 0
            buffer = set(closed)
            for pt in nxt:
                closed.add(pt)
            for pt in nxt:
                if pt in buffer:
                    continue
                height = max(self.maxHeight(pt, graph, closed) + 1, height)
            return height

    def bruteForceFindMinHeightTree(self, n: int, edges: List[List[int]]) -> List[int]:
        graph = self.buildTree(n, edges)
        height = {}
        min_height = 10000
        for i in range(n):
            h = self.maxHeight(i, graph, set([i]))
            min_height = min(min_height, h)
            if height.keys().__contains__(h):
                height[h].append(i)
            else:
                height.update({h:[i]})
        return height[min_height]

    def get_heights(self, graph, start):
        heights = {0:[start]}
        visited = set()
        stack = [(start, 0)]
        parent = {}

        while len(stack) != 0:
            print(stack, heights)
            points = []
            point, h = stack.pop()
            visited.add(point)
            
            for p in graph[point]:
                if p in visited:
                    continue
                stack.append((p, h+1))
                points.append(p)
                parent.update({p:point})
            if len(points) > 0:
                if heights.__contains__(h+1):
                    heights[h+1].extend(points)
                else:
                    heights.update({h+1:points})

        return heights, parent

    def findMinHeightTrees(self, n, edges) -> List[int]:
        if n == 1:
            return [0]
        graph = self.buildTree(n, edges)
        print(graph)
        height, _ = self.get_heights(graph, 0)
        max_height = max(height.keys())
        print(height, max_height)
        root = height[max_height][0]
        height, parent = self.get_heights(graph, root)
        max_height = max(height.keys())
        print(height, max_height, parent)

        n = height[max_height][0]

        for x in range(max_height // 2):
            n = parent[n]
        res = [n]
        
        if max_height % 2 == 1:
            res.append(parent[n])
        return res

if __name__ == '__main__':
    sol = Solution()
    h = sol.findMinHeightTrees(10, [[0,3],[1,3],[2,3],[4,3],[5,3],[4,6],[4,7],[5,8],[5,9]])
    print(h)
