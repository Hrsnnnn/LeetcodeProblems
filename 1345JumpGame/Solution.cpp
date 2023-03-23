#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

class Solution {
public:
    map< int, vector<int> > mp;
    void preProcess(vector<int> &arr) {
        for(int i=0;i<arr.size();i++) {
            if(mp.count(arr[i])) mp[arr[i]].push_back(i);
            else mp[arr[i]] = vector<int>(1, i);
        }
        for(int i=0;i<arr.size();i++) {
            cout << i << " " << arr[i] << " : ";
            for(int j=0;j<mp[arr[i]].size();j++) {
                cout << mp[arr[i]][j] << " ";
            }
            cout << endl;
        }
    }

    void bfs(vector<int> &arr, vector<int> &count, int start) {
        set<int> visited;
        int startStep = arr[start];
        queue<int> q;
        q.push(start);
        visited.insert(start);

        while(!q.empty()) {
            for(auto i=visited.begin();i!=visited.end();i++) 
                cout << *i << " ";
            cout << endl;
            for(int i=0;i<count.size();i++) 
                cout << count[i] << " ";
            cout << endl;
            cout << q.front() << endl;

            int tmp = q.front();
            visited.insert(tmp);
            int value = arr[tmp];
            q.pop();
            
            for(int i=0;i<mp[value].size();i++) {
                int sameIndex = mp[value][i];
                if(!visited.count(sameIndex)) {
                    q.push(sameIndex);
                    visited.insert(sameIndex);
                    count[sameIndex] = min(count[sameIndex], count[tmp]+1);
                }
            }

            if(tmp-1 >= 0 && !visited.count(tmp-1)) { visited.insert(tmp-1); q.push(tmp-1); count[tmp-1] = min(count[tmp-1], count[tmp]+1); }
            if(tmp+1 < arr.size() && !visited.count(tmp+1)) { visited.insert(tmp+1); q.push(tmp+1); count[tmp+1] = min(count[tmp+1], count[tmp]+1); }
        }
    }

    int minJumps(vector<int>& arr) {
        preProcess(arr);
        vector<int> count = vector<int>(arr.size());
        for(int i=0;i<count.size();i++) count[i] = arr.size();
        count[0] = 0;
        bfs(arr, count, 0);
        return count[count.size()-1];
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> v { 100,-23,-23,404,100,23,23,23,3,404 };
    int res = sol.minJumps(v);
    cout << "result is: " << res << endl;
    return 0;
}

