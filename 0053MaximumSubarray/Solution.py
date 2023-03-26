class Solution():

    def __init__(self) -> None:
        self.res = []
        pass

    def maxSubArray(self, nums):
        """
        """
        y, n, a = [nums[0]], [-10000], [nums[0]]
        for i in range(1, len(nums)):
            y.append(max(nums[i] + y[i-1], nums[i]))
            n.append(a[i-1])
            a.append(max(y[i], n[i]))
        self.res = a
        # print(y, n)
        return a[-1]
        
if __name__ == "__main__":
    sol = Solution()
    # arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
    arr = [5, 4, -1, 7, 8]
    print(arr)
    sol.maxSubArray(arr)
    print(sol.res)
