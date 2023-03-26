#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<queue>
#include<map>
#include<set>

using namespace std;

class Solution {
public:
    map<int, vector<int>> mp;
    void preProcess(vector<int> &arr) {
        for(int i=0;i<arr.size();i++) {
            if(mp.count(arr[i])) mp[arr[i]].push_back(i);
            else mp[arr[i]] = vector<int>();
        }
    }

    void bfs(vector<int> &arr, vector<int> &count, int start) {
        set<int> visited;
        int startStep = arr[start];
        queue<int> q;
        q.push(start);

        while(!q.empty()) {
            for(auto i=visited.begin();i!=visited.end();i++) 
                cout << *i << " ";
            cout << endl;

            int tmp = q.front();
            visited.insert(tmp);
            q.pop();
            
            for(int i=0;i<mp[tmp].size();i++) {
                int sameIndex = mp[tmp][i];
                if(!visited.count(sameIndex)) {
                    q.push(sameIndex);
                    visited.insert(sameIndex);
                    count[sameIndex] = min(count[sameIndex], count[tmp]+1);
                }
            }

            if(tmp-1 >= 0 && visited.count(tmp-1)) { visited.insert(tmp-1); q.push(tmp-1); count[tmp-1] = min(count[tmp-1], count[tmp]+1); }
            if(tmp+1 < arr.size() && visited.count(tmp+1)) { visited.insert(tmp+1); q.push(tmp+1); count[tmp+1] = min(count[tmp+1], count[tmp]+1); }
        }
    }

    int minJumps(vector<int>& arr) {
        preProcess(arr);
        vector<int> count = vector<int>(arr.size());
        for(int i=0;i<count.size();i++) count[i] = arr.size();
        bfs(arr, count, 0);
        return *count.cend();
    }
};