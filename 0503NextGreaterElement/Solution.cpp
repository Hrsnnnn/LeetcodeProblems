#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int nextIndex(int idx, int length) { return (idx + 1) % length; }

void displayResult(vector<int> res) {
    for(int i = 0; i < res.size(); i++) cout << res[i] << " ";
    cout << endl;
}
 
vector<int> nextGreaterElements(vector<int>& nums) {
    int size = nums.size();    
    vector<int> res(size);
    int *idx = new int[size * 2];
    for(int i = 0; i < size; i++) {
        nums.push_back(nums[i]);
        idx[i] = idx[i + size] = i;
    }
    stack<int> st; st.push(nums[0]);
    stack<int> idxst; idxst.push(idx[0]);

    for(int i = 1; i < size * 2; i++) {
        while(nums[i] > st.top()) {
            // cout << i << ", " << st.top() << ", " << idxst.top() << ", " << nums[i] << endl;
            // cout << i << " result: "; displayResult(res);
            int index = idxst.top();
            st.pop(); idxst.pop();
            res[index % size] = nums[i];
            if(st.size() == 0) break;
        }
        st.push(nums[i]);
        idxst.push(i);
    }

    while(!st.empty()) {
        int index = idxst.top();
        st.pop(); idxst.pop();
        if(index < size) res[index] = -1;
    }

    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> nums{1, 2, 1};
    displayResult(nums);
    displayResult(nextGreaterElements(nums));
    return 0;
}

