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

    int dfs(TreeNode* root, int curMax) {
        if (root == nullptr) {
            return 0;
        }

        int good = 0;

        good += (root->val >= curMax) ? 1 : 0;
        good += dfs(root->left, max(curMax, root->val));
        good += dfs(root->right, max(curMax, root->val));

        return good;
    }



    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);;
    }
};
