import sys

class Solution:
    def bisect(self, nums, value, l, r):
        while r - l > 1:
            index = (l + r) // 2
            if nums[index] < value:
                l = index
            elif nums[index] > value:
                r = index
            else:
                return index
        return r


    def LongestIncreaseSubsequenceLength(self, nums):
        tab, length = [0] * len(nums), 0
        for i in range(len(nums)):
            if nums[i] < tab[0]:
                tab[0] = nums[i]
            elif nums[i] > tab[length - 1]:
                tab[length] = nums[0]
                length += 1
            else:
                ceil = self.bisect(tab, nums[i], 0, length - 1)
                tab[ceil] = nums[i]
        
        return length
                

    def minimumMountainRemovals(self, nums):
        best = []

if __name__ == '__main__':
    sol = Solution()
    ind = sol.bisect([1, 2, 4, 6, 9], 3)
    print(ind)
