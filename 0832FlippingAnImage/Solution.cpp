#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        vector<vector<int>> res(image.size());
        for(int i=0;i<image.size();i++) res.push_back(vector<int>(image[i].size()));
        for(int i=0;i<image.size();i++) {
            for(int j=0;j<image[i].size();j++) {
                res[i][j] = image[image.size()-i-1][image[i].size()-j-1];
                res[i][j] = res[i][j] == 0 ? 1 : 0;
            }
        }
        return res;
    }
};