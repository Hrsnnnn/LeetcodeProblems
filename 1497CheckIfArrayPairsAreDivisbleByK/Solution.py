from typing import List

class Solution:
    def canArrange(self, arr: List[int], k: int) -> bool:
        pair = {}
        for i in range(k):
            pair.update({i:0})

        for num in arr:
            pair[num % k] += 1

        for key in pair.keys():
            if key == 0:
                if pair[key] != 0:
                    return False
            elif pair[key] != pair[k-key]:
                return False
        
        return True
