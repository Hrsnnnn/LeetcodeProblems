#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;

class Solution {
public:
    int eatTimes(map<int, int> &cnt, vector<int> v, int eat) {
        if(cnt.count(eat)) return cnt[eat];
        int count = 0;
        for(int i=0;i<v.size();i++) {
            count += ceil(v[i] / eat);
        }
        cnt.insert({eat, count});
        return count;
    }

    int binarySearch(map<int, int> &cnt, const vector<int> &arr, int l, int r) {
        return 0;
    }

    int BruteForceSearch(map<int, int> &cnt, vector<int> arr, int target) {
        int maxVal = *(max_element(arr.cbegin(), arr.cend()));
        for(int i=accumulate(arr.begin(), arr.end(), 0)/target;i<maxVal;i++) {
            int res = eatTimes(cnt, arr, i);
            if(res == target) return i;
        }
        return maxVal;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        map<int, int> cnt;              // eatNum -> eatTime
        return BruteForceSearch(cnt, piles, h);
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}

