#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

class Solution {
public:
    bool isPrime(int i, int j) {
        int maxVal = max(i, j);
        int minVal = min(i, j);
        while(true) {
            int tmp = maxVal % minVal;
            if(tmp == 0) return minVal;
            maxVal = minVal;
            minVal = tmp;
        }
        return minVal;
    }
    bool isGoodArray(vector<int>& nums) {
        set<int> primes;
        for(int i=0;i<nums.size();i++) {
            for(int j=i;j<nums.size();j++) {
                int prime = isPrime(nums[i], nums[j]);
                if(prime == 1) return true;
                primes.insert(prime);
            }
        }

        vector<int> v(primes.begin(), primes.end());

        for(int i=0;i<v.size();i++) {
            for(int j=i;j<v.size();j++) {
                if(isPrime(v[i], v[j]) == 1) return true;
            }
        }

        return false;
    }
};