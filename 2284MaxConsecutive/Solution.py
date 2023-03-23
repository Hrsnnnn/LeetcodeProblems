from typing import List

class Solution:
    def maxConsecutive(self, bottom: int, top: int, special: List[int]) -> int:
        special = sorted(special)
        res = 0
        curr = bottom
        for s in special:
            if s < bottom:
                continue
            if s > top:
                curr = s
                break

            # print(curr, s)
            res = max(s - curr, res)
            curr = s + 1
        res = max(res, top - curr + 1)
        return res

if __name__ == '__main__':
    sol = Solution()
    res = sol.maxConsecutive(6, 8, [7, 6, 8])
    print(res)
    pass
