#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int lastday = days[days.size()-1];
        vector<int> dp(lastday, 0);
        int day_idx = 0;
        for(int i=0;i<dp.size();i++) {
            if(i == days[day_idx]-1) {
                if(i == 0) dp[i] = min(min(costs[0], costs[1]), costs[2]);
                else if(i < 7) dp[i] = min(min(dp[i-1]+costs[0], costs[1]), costs[2]);
                else if(i < 30) dp[i] = min(min(dp[i-1]+costs[0], dp[i-7]+costs[1]), costs[2]);
                else dp[i] = min(min(dp[i-1]+costs[0], dp[i-7]+costs[1]), dp[i-30]+costs[2]);
                day_idx += 1;
            }
            else {
                dp[i] = i == 0 ? 0 : dp[i-1];
            }
        }
        return dp[dp.size()-1];
    }
};
