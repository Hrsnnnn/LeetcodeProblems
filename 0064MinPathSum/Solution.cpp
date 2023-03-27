#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> sum(100*200, 0);
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[i].size();j++) {
                if(i == 0 && j == 0) sum[j] = grid[i][j];
                else if(j == 0) sum[j] = sum[j] + grid[i][j];
                else sum[j] = min(sum[j]+grid[i][j], sum[j-1]+grid[i][j]);
            }
        }
        return sum[sum.size()-1];
    }
};
