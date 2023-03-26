#include<iostream>
#include<string>
#include<stack>
#include<vector>

using namespace std;

class Solution {
    public:
    bool isDigits(string s) {
        if(s.at(0) <= '9' && s.at(0) >= '0') return true;
        else if(s.at(0) == '-' && s.length() != 1) return true;
        else return false;
    }

    int evalRPN(vector<string> &tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++) {
            if(isDigits(tokens.at(i))) st.push(stoi(tokens.at(i)));
            else {
                int a1 = st.top(); st.pop();
                int a2 = st.top(); st.pop();
                string c = tokens.at(i);
                if(c == "+") st.push(a1 + a2);
                else if(c == "-") st.push(a2 - a1);
                else if(c == "*") st.push(a1 * a2);
                else st.push(a2 / a1);
            }
        }
        return st.top();
    }
};

int main(int argc, char const *argv[])
{
    cout << (int)13 / 5 << endl;
    return 0;
}

