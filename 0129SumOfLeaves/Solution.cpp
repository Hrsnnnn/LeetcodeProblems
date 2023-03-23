#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    int result;
    void sumTree(TreeNode* root, int base) {
        if(!root) return;
        else if(!root->left && !root->right) result += (base * 10 + root->val);
        else {
            sumTree(root->left, base*10+root->val);
            sumTree(root->right, base*10+root->val);
        }
    }

    int sumNumbers(TreeNode* root) {
        sumTree(root, 0);
        return result;
    }
};