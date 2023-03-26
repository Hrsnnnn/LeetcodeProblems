#include<iostream>
#include<math.h>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    int depth;
    TreeNode() : val(0), left(nullptr), right(nullptr), depth(0) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr), depth(0) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    TreeNode(int x, TreeNode *left, TreeNode *right, int depth) : val(x), left(left), right(right), depth(depth) {}
};

class Solution {
public:
    TreeNode* BuildTree(int* arr, int index, int length, int depth=0) {
        if(index >= length) return nullptr;
        if(arr[index] == -1) return nullptr;
        TreeNode* node = new TreeNode();
        cout << "buildtree: " << arr[index] << ", " << index << endl;
        node -> val = arr[index];
        node -> left = BuildTree(arr, 2 * index + 1, length, depth + 1);
        node -> right = BuildTree(arr, 2 * index + 2, length, depth + 1);
        node -> depth = depth;
        return node;
    }

    void DisplayTree(queue<TreeNode*> q) {
        if(q.empty()) return;
        TreeNode* n = q.front();
        if(n == nullptr) { q.pop(); DisplayTree(q); return; }
        cout << n -> val << " " << n -> depth << endl;
        q.push(n -> left); q.push(n -> right); q.pop();
        DisplayTree(q);
    }

    void CalDiff(TreeNode* root, int mx, int mn, int &res) {
        if(root == nullptr) return;
        res = res > abs(mx - root -> val) ? res : abs(mx - root -> val);
        res = res > abs(root -> val - mn) ? res : abs(root -> val - mn);

        cout << root->val << ", " << root -> depth << ", " << res << ", ";
        cout << mx << ", " << mn << endl;

        mx = root -> val > mx ? root -> val : mx;
        mn = root -> val < mn ? root -> val : mn;
        CalDiff(root -> left, mx, mn, res);
        CalDiff(root -> right, mx, mn, res);
    }

    int maxAncestorDiff(TreeNode* root) {
        int res = 0;
        CalDiff(root, root -> val, root -> val, res);
        return res;
    }

};

int main(int argc, char const *argv[]) {
    // int arr[] = {8, 3, 10, 1, 6, -1, 14, -1, -1, 4, 7, 13};
    // int length = 12;
    int arr[] = {1, -1, 2, -1, 0, 3};
    int length = 6;
    Solution * sol = new Solution();
    TreeNode* root = sol -> BuildTree(arr, 0, 12, 0);
    queue<TreeNode*> q; q.push(root); sol -> DisplayTree(q);
    int res = sol -> maxAncestorDiff(root);
    cout << res << endl;
    return 0;
}
