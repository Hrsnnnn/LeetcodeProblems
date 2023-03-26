
class Solution:
    def __init__(self) -> None:
        pass

    def nextGreaterElement(self, n):
        if n >= 2 **31:
            return -1
        digits = []
        buffer = n
        while buffer != 0:
            digits.append(buffer % 10)
            buffer = buffer // 10

        print('digits: ', digits)
        
        change = False
        
        for i in range(1, len(digits)):
            min_before = digits[i - 1]
            before = digits[:i]
            anchor = digits[i]
            for d in before:
                if d > anchor and d < min_before:
                    min_before = d

            print('before: ', before)
            print('min_before', min_before, 'anchor', anchor)

            if anchor < digits[i - 1]:
                digits[i] = min_before
                before.remove(min_before)
                before.append(anchor)
                before.sort(reverse=True)
                print('before updated: ', before)
                digits[:i] = before
                change = True
                break

        if change == False:
            return -1

        res = 0
        for i in range(len(digits)):
            res += digits[i] * 10 ** i
        
        if res >= 2 ** 31:
            return -1

        return res

if __name__ == '__main__':
    sol = Solution()
    print(sol.nextGreaterElement(230241))
