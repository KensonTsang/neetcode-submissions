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

    void dfs (TreeNode* root, int& result, int& k) {

        if (root == nullptr) {
            return;
        }

        if (k == 0) {       // result found
            return;
        }

        dfs(root->left, result, k);

        k--;
        if (k == 0) {
            result = root->val;
        }

        dfs(root->right, result, k);

    }


    int kthSmallest(TreeNode* root, int k) {
        int result = 0;
        dfs(root, result, k);
        return result;
    }
};
