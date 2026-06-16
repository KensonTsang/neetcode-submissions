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

    bool dfs (TreeNode* root, int lowerBound, int upperBound) {
        if (root == nullptr) {
            return true;
        }

        if (root->val <= lowerBound || root->val >= upperBound) {
            return false;
        }

        return dfs(root->left, lowerBound, root->val) && dfs(root->right, root->val, upperBound);

    }

    bool isValidBST(TreeNode* root) {
        return dfs(root, INT_MIN, INT_MAX);
    }
};
