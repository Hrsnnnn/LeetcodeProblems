def sortstring(string):
        l = list(string)
        l.sort()
        return ''.join(l)

def groupAnagrams(strs):
        dic = {}
        res = []
        for string in strs:
            bs = sortstring(string)
            
            if not bs in dic.keys():
                dic.update({bs:[string]})
            else:
                dic[bs].append(string)
                
        for key in dic:
            l = []
            for string in dic[key]:
                l.append(string)
            res.append(l)
        return res

print(groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]))
