#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
    public:
        string frequencySort(string s) {
            int count[127];
            for(int i = 0; i < 127; i++) count[i] = 0;
            for(int i = 0; i < s.length(); i++) {
                count[s.at(i)] += 1;
            }
            sort(s.begin(), s.end(), [count](char a, char b) {
                if(count[a] == count[b]) return a < b;
                return count[a] > count[b]; 
            });
            return s;
        }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string res = s.frequencySort(string("loveleetcode"));
    cout << res << endl;
}

