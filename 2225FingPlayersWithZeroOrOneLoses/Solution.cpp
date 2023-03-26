#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        Solution() {}
        vector<vector<int>> findWinners(vector<vector<int>>& matches);
        void displayResult(vector<vector<int>> &res);
};

vector<vector<int>> Solution::findWinners(vector<vector<int>>& matches) {
    // check largest number
    int namecount = 0;
    for (int i = 0; i < matches.size(); i++)
        for (int j = 0; j < matches[i].size(); j++)
            if (namecount < matches[i][j]) namecount = matches[i][j];
    
    // displayResult(matches);

    int *namelist = new int[namecount + 1]; // cout << "namecount: " << namecount << endl;
    for (int i = 0; i < namecount + 1; i++) namelist[i] = -1;
    vector<int> zeros(0); vector<int> ones(0);

    for (int i = 0; i < matches.size(); i++) {
        int winner = matches[i][0]; int loser = matches[i][1];
        if (namelist[loser] == -1) namelist[loser] = 1;
        else namelist[loser] += 1;
        if (namelist[winner] == -1) namelist[winner] = 0; 
    }

    for (int i = 0; i < namecount + 1; i++) {
        if (namelist[i] == 0) zeros.push_back(i);
        if (namelist[i] == 1) ones.push_back(i);
    }

    vector<vector<int>> result(0);
    result.push_back(zeros); result.push_back(ones);
    displayResult(result);
    return result;
}

void Solution::displayResult(vector<vector<int>> &res) {
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    Solution *sol = new Solution();
    // int mat[10][2] = { {1,3},{2,3},{3,6},{5,6},{5,7},{4,5},{4,8},{4,9},{10,4},{10,9} };
    int mat[4][2] = { {2,3},{1,3},{5,4},{6,4} };
    vector<vector<int>> matches(0);

    for (int i = 0; i < 4; i++) matches.push_back(*new vector<int>(mat[i], mat[i]+2));

    sol -> findWinners(matches);
    return 0;
}

/*
=================================================================
==31==ERROR: AddressSanitizer: alloc-dealloc-mismatch (operator new [] vs operator delete) on 0x6040000000d0
    #3 0x7fce792bf0b2  (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
0x6040000000d0 is located 0 bytes inside of 44-byte region [0x6040000000d0,0x6040000000fc)
allocated by thread T0 here:
    #3 0x7fce792bf0b2  (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
==31==HINT: if you don't care about these errors you may set ASAN_OPTIONS=alloc_dealloc_mismatch=0
==31==ABORTING*/

