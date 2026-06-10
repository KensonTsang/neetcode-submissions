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

    bool isBalanceBool;

    int dfs (TreeNode* root) {

        if (root == nullptr) {
            return 0;
        }


        int leftHeight = dfs(root->left);
        int rightHeight = dfs(root->right);

       
        if (isBalanceBool)
        {
            isBalanceBool = abs(leftHeight - rightHeight) <= 1;
        }
   

        return 1 + max(leftHeight, rightHeight);

    }

    bool isBalanced(TreeNode* root) {
        
        isBalanceBool = true;

        dfs(root);

        return isBalanceBool;

    }
};
