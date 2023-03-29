#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int res = 0;
        for(int i=0;i<satisfaction.size();i++) {
            int tmp = 0;
            for(int j=i;j<satisfaction.size();j++) {
                tmp += (j - i) * satisfaction[j];
            }
            res = max(res, tmp);
        }
        return res;
    }
};
