

class Solution:
    def bisect(self, nums, value):
        l, r = 0, len(nums)
        while(r - l > 1):
            mid = (l + r) // 2
            if value > nums[mid]:
                l = mid
            elif value < nums[mid]:
                r = mid
            else:
                return mid

    def findMedianSortedArrays(self, nums1, nums2):
        if len(nums1) < len(nums2):
            return self.findMedianSortedArrays(nums2, nums1)
        
        if len(nums2) == 0:
            nums2 = nums1
        
        if len(nums1) == 1:
            if len(nums2) == 0:
                return nums1[0]
            elif len(nums2) == 1:
                return (nums1[0] + nums2[0]) / 2

        l, r = 0, len(nums1)
        total_length = (len(nums1) + len(nums2))
        half_length = total_length // 2

        while r > l + 1:
            mid1 = (l + r) // 2
            mid2 = half_length - mid1

            print(l, r, mid1, mid2)

            x = -100000 if mid1 == 0 else nums1[mid1 - 1]
            y = 100000 if mid1 == len(nums1) else nums1[mid1]
            z = -100000 if mid2 == 0 else nums2[mid2 - 1]
            u = 100000 if mid2 == len(nums2) else nums2[mid2]

            if x <= u and z <= y:
                print("final:")
                print(nums1[:mid1], nums1[mid1:])
                print(nums2[:mid2], nums2[mid2:])
                if total_length % 2 == 0:
                    return (max(x, z) + min(y, u)) / 2
                else:
                    return (min(y, u))
            elif x > u:
                r = mid1
            elif y < z:
                l = mid1
            print(x, y, z, u)
            print(nums1[:mid1], nums1[mid1:])
            print(nums2[:mid2], nums2[mid2:])

        x = -100000 if mid1 == 0 else nums1[mid1 - 1]
        y = 100000 if mid1 == len(nums1) else nums1[mid1]
        z = -100000 if mid2 == 0 else nums2[mid2 - 1]
        u = 100000 if mid2 == len(nums2) else nums2[mid2]

        if total_length % 2 == 0:
            if l == 0:
                return (y + z) / 2
            elif r == len(nums1):
                return (x + u) / 2
        else:
            if l == 0:
                return y
            elif r == len(nums1):
                return u

if __name__ == "__main__":
    n1 = [1, 3, 5, 7, 9]
    n2 = [2, 4, 6, 8]

    n1 = [1]
    n2 = [2, 3]

    sol = Solution()
    res = sol.findMedianSortedArrays(n1, n2)
    print(res)
