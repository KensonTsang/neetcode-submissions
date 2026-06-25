/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    int dfs (TreeNode* root, int maxNum) {
        if (root == nullptr) {
            return 0;
        }

        int good = root->val >= maxNum;

        good += dfs(root->left, max(maxNum, root->val));
        good += dfs(root->right, max(maxNum, root->val));

        return good;
    }


    int goodNodes(TreeNode* root) {
        return dfs(root, -101);
    }
};
