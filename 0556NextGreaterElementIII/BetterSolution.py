
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
        anchor = len(digits)
        
        for i in range(1, len(digits)):
            if digits[i - 1] > digits[i]:
                anchor = i
                break

        if anchor == len(digits):
            return -1
        
        swap = 0
        for i in range(0, anchor):
            if digits[i] > digits[anchor]:
                swap = i
                break
        

        print(anchor, swap, digits)
        digits[anchor], digits[swap] = digits[swap], digits[anchor]
        digits[0:anchor] = digits[0:anchor][::-1]

        res = 0
        for i in range(len(digits)):
            res += digits[i] * 10 ** i
        
        if res >= 2 ** 31:
            return -1

        return res
 

if __name__ == '__main__':
    sol = Solution()
    print(sol.nextGreaterElement(39568))
