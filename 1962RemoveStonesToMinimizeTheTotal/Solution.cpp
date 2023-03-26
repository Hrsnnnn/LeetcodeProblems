#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>

using namespace std;

class Solution {
    public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue <int, vector<int>, less<int>> q;
        for(int i=0;i<piles.size();i++) q.push(piles[i]);
        for(int i=0;i<k;i++) { int b = q.top(); q.pop(); q.push(ceil(b / 2)); }
        int sum = 0;
        for(int i=0;i<q.size();i++) { cout << q.top() << " "; sum += q.top(); q.pop(); } 
        return sum;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    auto sol = Solution();
    return 0;
}

