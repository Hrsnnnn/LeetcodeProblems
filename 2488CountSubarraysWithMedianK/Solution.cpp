#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int res = 0;
        int kidx = -1;
        for(int i=0;i<nums.size();i++) if(nums.at(i) == k) { kidx = i; break; }
        int leftanchor = kidx, rightanchor = kidx;
        int lgt = 0, llt = 0;
        int rgt = 0, rlt = 0;

        map<int, int> back_res;
        for(int i=kidx;i<nums.size();i++) {
            if(nums.at(i) == k) { }
            else if(nums.at(i) < k) rlt += 1;
            else rgt += 1;
            if(back_res.find(rgt - rlt) != back_res.end()) back_res.at(rgt-rlt) += 1;
            else back_res.insert(pair<int, int>(rgt - rlt, 1));
        }

        rgt = rlt = 0;

        for(;leftanchor>=0;leftanchor--) {
            if(leftanchor == kidx) llt = lgt = 0;
            else if(nums.at(leftanchor) < k) llt += 1;
            else lgt += 1;
            
            if(back_res.find(llt-lgt) != back_res.end()) res += back_res.at(llt-lgt);
            if(back_res.find(llt-lgt+1) != back_res.end()) res += back_res.at(llt-lgt+1);
        }

        // for(;leftanchor>=0;leftanchor--) {
        //     if(leftanchor == kidx) llt = lgt = 0;
        //     else if(nums.at(leftanchor) < k) llt += 1;
        //     else lgt += 1;
        //     rlt = rgt = 0;
        //     for(rightanchor=kidx;rightanchor<nums.size();rightanchor++) {
        //         if(rightanchor == kidx) rlt = rgt = 0;
        //         else if(nums.at(rightanchor) < k) rlt += 1;
        //         else rgt += 1;

        //         if(rgt + lgt == rlt + llt) res += 1;
        //         else if(rgt + lgt == rlt + llt + 1) res += 1;
        //     }
        // }
        return res;
    }
};