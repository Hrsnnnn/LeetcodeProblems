class Solution:
    def numTilings(self, n: int) -> int:
        if n == 1:
            return 1
        elif n == 2:
            return 2
        elif n == 3:
            return 5
        nums = [0 for i in range(n+1)]
        nums[0], nums[1], nums[2] = 1, 2, 5
        for i in range(3, n):
            nums[i] = 2 * nums[i-3] + nums[i-1]
        return nums[n-1] % (10 ** 9 + 7)
