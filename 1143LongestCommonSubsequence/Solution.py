import typing

class Solution:
    def longestCommonSubsequence(self, text1:str, text2:str) -> int:
        mat = [[0] * len(text2) for i in range(len(text1))]

        for i in range(len(text1)):
            for j in range(len(text2)):
                # print(i, j)
                if text1[i] == text2[j]:
                    if i == 0 or j == 0:
                        mat[i][j] = 1
                    else:
                        mat[i][j] = mat[i-1][j-1] + 1
                else:
                    if i == 0:
                        mat[i][j] = mat[i][j-1]
                    elif j == 0:
                        mat[i][j] = mat[i-1][j]
                    else:
                        mat[i][j] = max(mat[i-1][j], mat[i][j-1])
        # print(mat)
        return mat[len(text1)-1][len(text2)-1]


if __name__ == '__main__':
    sol = Solution()
    sol.longestCommonSubsequence('bl', 'yby')
