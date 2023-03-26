from typing import List

class Solution:
    def maxValueAfterReverse(nums:List[int]):
        diff = []
        max_diff = -1
        for idx in range(len(nums) - 1):
            diff.append(abs(nums[idx]-nums[idx+1]))
        origin_diff = sum(diff)

        for i in range()
        
        for i in range(len(nums) - 1):
            for j in range(i+1, len(nums)):
                if i == 0:
                    if j == len(nums) - 1:
                        continue
                    d = abs(nums[j+1]-nums[i]) - abs(nums[j+1]-nums[j])
                    max_diff = max(d, max_diff)
                elif j == len(nums) - 1:
                    if i == 0:
                        continue
                    d = abs(nums[i-1]-nums[j]) - abs(nums[i-1]-nums[i])
                    max_diff = max(d, max_diff)
                else:
                    d = abs(nums[i]-nums[j+1]) + abs(nums[i-1]-nums[j]) - abs(nums[i]-nums[i-1]) - abs(nums[j+1]-nums[j])
                    max_diff = max(d, max_diff)
        return origin_diff + max_diff
