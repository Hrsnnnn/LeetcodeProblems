#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector< vector<int> >& matrix) {
        vector<int> luckyNums;
        for(int i=0;i<matrix.size();i++) {
            int minCol = 0; bool lucky = true;
            for(int j=0;j<matrix[i].size();j++) minCol = matrix[i][minCol] <= matrix[i][j] ? minCol : j;
            for(int j=0;j<matrix.size();j++) if(matrix[i][minCol] < matrix[j][minCol]) { lucky = false; break; }
            if(lucky) luckyNums.push_back(matrix[i][minCol]);
        }
        return luckyNums;
    }
};