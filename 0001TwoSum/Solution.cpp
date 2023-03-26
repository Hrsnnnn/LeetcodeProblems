#include<iostream>
#include<set>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        map<int, int> st;
        for(int i=0;i<nums.size();i++) st.insert({nums[i], i});
        for(int i=0;i<nums.size();i++) {
            if(st.count(target-nums[i]) && st[target-nums[i]] != i) { v.push_back(i); v.push_back(st[target-nums[i]]); break; }
        }
        return v;
    }
};
