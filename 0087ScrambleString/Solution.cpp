#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<map>

using namespace std;

class Solution {
public:
    map<string, bool> mp;
    bool ismatch(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        for(int i=0;i<s1.size();i++) if(s1[i] != s2[i]) return false;
        return true;
    }

    bool match(string s1, string s2) {
        if(mp.count(s1+" "+s2)) return mp[s1+" "+s2]; 
        if(!ismatch(s1, s2)) return false;
        if(s1.size() == 1) return true;

        for(int i=0;i<s1.size();i++) {
            int split = i;
            string s1front = s1.substr(0, split); 
            string s1back = s1.substr(split);
            string s2front_front = s2.substr(0, split);
            string s2front_back = s2.substr(split);
            string s2back_front = s2.substr(0, s2.size()-split);
            string s2back_back = s2.substr(s2.size()-split);
            if(match(s1front, s2front_front) && match(s1back, s2front_back) || match(s1front, s2back_back) && match(s1back, s2back_front)) {
                mp.insert({s1+" "+s2, true});
                return true;
            }
        }
        mp.insert({s1+" "+s2, false});
        return false;
    }

    bool isScramble(string s1, string s2) {
        return match(s1, s2);
    }
};
