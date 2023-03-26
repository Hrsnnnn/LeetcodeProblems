#include<iostream>
#include <vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        for(int i=0;i<capacity.size();i++) { capacity[i] = capacity[i] - rocks[i]; }
        sort(capacity.begin(), capacity.end());
        int nums = 0;
        for(int i=0;i<capacity.size();i++) {
            nums = nums + capacity[i];
            if(nums > additionalRocks) return i;
        }
        return capacity.size();
    }
};