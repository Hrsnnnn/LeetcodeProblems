#include<vector>
#include<iostream>
#include<map>
#include<set>

using namespace std;

class Solution {
public:

    void dfs(int start, set<int>& visited, map<int, set<int> >& graph) {
        visited.insert(start);
        set<int>::iterator it = graph[start].begin();
        for(;it!=graph[start].end();it++) {
            if(!visited.count(*it)) dfs(*it, visited, graph);
        }
        return;
    }
    
    int makeConnected(int n, vector< vector<int> >& connections) {
        if(connections.size() < n - 1) return -1;

        map<int, set<int> > graph;
        set<int> visited;
        for(int i=0;i<connections.size();i++) {
            int start = connections[i][0]; int end = connections[i][1];
            if(graph.count(start)) graph[start].insert(end);
            else { graph[start] = set<int>(); graph[start].insert(end); }
            if(graph.count(end)) graph[end].insert(start);
            else { graph[end] = set<int>(); graph[end].insert(start); }
        }

        int res = -1;
        for(int i=0;i<n;i++) {
            if(!visited.count(i)) { res += 1; dfs(i, visited, graph); }
        }
        return res;
    }
};