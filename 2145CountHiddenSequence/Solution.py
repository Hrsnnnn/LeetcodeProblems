from typing import List

class Solution:
    def numberOfArrays(self, differences: List[int], lower: int, upper: int) -> int:
        num = lower
        maxval, minval = -100000, 100000
        maxval = max(num, maxval)
        minval = min(num, minval)
        for d in differences:
            num = num + d
            maxval = max(num, maxval)
            minval = min(num, minval)
        
        res = 0
        while maxval <= upper:
            maxval += 1
            minval += 1
            if minval < lower + 1:
                continue
            print(maxval, minval)
            res += 1
        
        return res


if __name__ == '__main__':
    sol = Solution()
    res = sol.numberOfArrays([83, -5], -82, 14)
    print(res)
