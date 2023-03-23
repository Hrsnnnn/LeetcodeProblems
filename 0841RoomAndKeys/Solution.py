from typing import List

from aiohttp import ETag
from torch import true_divide

class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        st = [0]
        visited = set()
        while len(st) > 0:
            point = st.pop()
            visited.add(point)
            neighbors = rooms[point]
            for n in neighbors:
                if n in visited:
                    continue
                st.append(n)
        if len(visited) == len(rooms):
            return True
        return False
