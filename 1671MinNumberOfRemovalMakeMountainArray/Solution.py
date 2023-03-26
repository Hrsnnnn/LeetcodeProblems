import sys

class Solution:
    def minimumMountainRemovals(self, nums):
        n = len(nums)
        inc, dec = [0] * n, [0] * n

        for i in range(n):
            for j in range(0, i):
                inc[i] = max(inc[i], inc[j] + 1)
        
        for i in range(n-2, -1, -1):
            for j in range(n-1, i, -1):
                dec[i] = max(dec[i], dec[j] + 1)
        
        for i in range(0, n):
            if inc[i] > 0 and dec[i] > 0:
                res = max(res, inc[i] + dec[i])
        
        return n - res - 1
