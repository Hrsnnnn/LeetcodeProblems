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

    TreeNode* build(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0) return nullptr; 
        if(inorder.size() == 1) return new TreeNode(inorder[0]);
        int root = postorder[postorder.size()-1];
        int rootidx = -1;
        for(int i=0;i<inorder.size();i++) if(inorder[i] == root) { rootidx = i; break; }
        vector<int> inleft = vector<int>(inorder.cbegin(), inorder.cbegin()+rootidx);
        vector<int> inright = vector<int>(inorder.cbegin()+rootidx+1, inorder.cend());
        vector<int> postleft = vector<int>(postorder.cbegin(), postorder.cbegin()+rootidx);
        vector<int> postright = vector<int>(postorder.cbegin()+rootidx, postorder.cend()-1);
        TreeNode* rootNode = new TreeNode(root);
        rootNode -> left = build(inleft, postleft);
        rootNode -> right = build(inright, postright);
        return rootNode;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, postorder);
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}

