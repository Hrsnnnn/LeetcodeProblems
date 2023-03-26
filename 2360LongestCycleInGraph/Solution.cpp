#include<iostream>
#include<vector>
#include<set>
#include<map>

using namespace std;

class Solution {
public:
    set<int> st;
    int LengthCycle(vector<int>& edges, int start) {
        int res = -1;
        map<int, int> mp;
        int tmp = start;
        int length = 0;
        while(edges[tmp] != -1) {
            if(st.count(tmp)) return -1;
            mp[tmp] = length;
            length++;
            tmp = edges[tmp];
            if(mp.count(tmp)) { res = length - mp[tmp]; break; } 
        }

        bool b = false;
        for(auto i:mp) {
            if(i.first == start) b = true;
            if(b) st.insert(i.first);
        }
        return -1;
    }

    int longestCycle(vector<int>& edges) {
        int res = -1;
        for(int i=0;i<edges.size();i++) {
            if(st.count(i)) continue;
            int tmp = LengthCycle(edges, i);
            res = res > tmp ? res : tmp;
        }
        return res;
    }
};