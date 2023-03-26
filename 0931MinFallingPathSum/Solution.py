from typing import List

class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        if len(matrix[0]) == 1:
            res = 0
            for m in matrix:
                res += m[0]
            return res
            
        x = [[0] * len(matrix) for i in range(len(matrix[0]))]
        x[0] = matrix[0]
        for i in range(1, len(matrix)):
            for j in range(len(matrix[i])):
                val = matrix[i][j]
                if j == 0:
                    x[i][j] = min(x[i-1][j], x[i-1][j+1]) + val
                elif j == len(matrix[i]) - 1:
                    x[i][j] = min(x[i-1][j-1], x[i-1][j]) + val
                else:
                    x[i][j] = min(x[i-1][j-1], x[i-1][j], x[i-1][j+1]) + val
                
        return min(x[len(x[0])-1])

if __name__ == '__main__':
    sol = Solution()
    mat = [[100,-42,-46,-41],[31,97,10,-10],[-58,-51,82,89],[51,81,69,-51]]
    print(mat)
    res = sol.minFallingPathSum(mat)
    print(res)
