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

    int result;

    int dfs(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftResult = max(dfs(root->left), 0);
        int rightResult = max(dfs(root->right), 0);

        int curResult = root->val + leftResult + rightResult;
        result = max(curResult, result);

        return root->val + max(leftResult, rightResult);
    }

    int maxPathSum(TreeNode* root) {
        result = INT_MIN;
        dfs(root);
        return result;
    }
};
