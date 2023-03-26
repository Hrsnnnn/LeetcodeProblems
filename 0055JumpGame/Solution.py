from typing import List

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        if nums[0] == 0:
            return False
        maxidx = 0

        for i in range(len(nums)):
            if i <= maxidx:
                maxidx = max(maxidx, i + nums[i])
            else:
                return False
        return True

if __name__ == '__main__':
    sol = Solution()
    testcases = [
        [2,3,1,1,4],
        [3,2,1,0,4],
        [1,0,3,4,5],
        [2,0,0,3,4]
    ]
    for t in testcases:
        res = sol.canJump(t)
        print(t, res)
