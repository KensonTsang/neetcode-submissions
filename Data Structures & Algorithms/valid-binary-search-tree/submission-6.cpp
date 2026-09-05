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

    bool dfs (TreeNode* root, int rootMin, int rootMax) {

        if (root == nullptr) {
            return true;
        }

        if (root->val <= rootMin || root->val >= rootMax) {
            return false;
        }

        return dfs (root->left, rootMin, root->val) &&
               dfs (root->right, root->val, rootMax);

    }


    bool isValidBST(TreeNode* root) {
        return dfs(root, INT_MIN, INT_MAX);
    }
};
