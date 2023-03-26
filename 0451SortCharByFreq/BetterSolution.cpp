#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        vector<string> v(127);
        for(auto i:s) v[i]+=i;
        sort(v.begin(),v.end(),[](const string& s1,const string& s2){
            return  s1.size()>s2.size();});
        string res;
        for(auto i:v) res+=i;
        return res;
    }
};