from typing import List

class Solution:
    def destroyTargets(self, nums: List[int], space: int) -> int:
        st = set()
        dic = {}
        for n in nums:
            st.add(n % space)
        for k in st:
            dic.update({k:[]})
        
        for n in nums:
            dic[n%space].append((n%space, n))
        
        maxlen = 0
        maxlist = []
        for k in dic.keys():
            if len(dic[k]) > maxlen:
                maxlen = len(dic[k])

        for k in dic.keys():
            if len(dic[k]) == maxlen:
                maxlist.extend(dic[k])

        maxlist = sorted(maxlist, key=lambda x:x[1])
        # print(maxlist, dic)
        return maxlist[0][1]
        

if __name__ == '__main__':
    sol = Solution()
    testcases = [
        ([3,7,8,1,1,5], 2),
        ([1,3,5,2,4,6], 2)
    ]
    for t in testcases:
        res = sol.destroyTargets(t[0], t[1])
        print(res)
