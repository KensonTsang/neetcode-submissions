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

    bool insertNode(TreeNode* root, int val) {

        if (root == nullptr) {
            return true;
        }

        if (val > root->val) {
            if(insertNode(root->right, val)) {
                root->right = new TreeNode(val);
                return false;
            }
        }
        else
        {
            if(insertNode(root->left, val)) {
                root->left = new TreeNode(val);
                return false;
            }
        }

        return false;

    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode(val);
        }


        insertNode(root, val);        
        return root;
    }
};