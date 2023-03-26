#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int min(const vector<int> &v) {
        int min = 0;
        for(int i=0;i<v.size();i++) min = v[i] < v[min] ? i : min;
        return min;
    }

    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> idx(primes.size(), 0);
        vector<int> uglyNumbers(1, 1);
        vector<int> tmp(primes.size());

        for(int i=0;i<tmp.size();i++) tmp[i] = primes[i];

        while(uglyNumbers.size() != n) {

            for(int i=0;i<tmp.size();i++) cout << tmp[i] << " ";
            cout << endl;
            for(int i=0;i<idx.size();i++) cout << idx[i] << " ";
            cout << endl;
            for(int i=0;i<uglyNumbers.size();i++) cout << uglyNumbers[i] << " ";
            cout << endl;

            int minidx = min(tmp);
            int nextUgly = tmp[minidx];
            uglyNumbers.push_back(tmp[minidx]);
            for(int i=0;i<tmp.size();i++) {
                if(tmp[i] == nextUgly) {
                    idx[i] ++;
                    tmp[i] = uglyNumbers[idx[i]] * primes[i];
                }
            }
            
        }

        return uglyNumbers[n-1];
    }
};
