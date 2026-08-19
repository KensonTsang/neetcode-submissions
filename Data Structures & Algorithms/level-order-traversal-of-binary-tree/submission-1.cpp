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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result{};
        
        if (root == nullptr) {
            return result;
        }

        queue<TreeNode*> q{};
        q.push(root);

        while (q.size() > 0) {

            int qSize = q.size();
            vector<int> r{};

            for (int i = 0 ; i < qSize ; ++i){

                auto* node = q.front();
                q.pop();

                if (node->left != nullptr) {
                    q.push(node->left);                    
                }

                if (node->right != nullptr) {
                    q.push(node->right);
                }

                r.push_back(node->val);
            }

            result.push_back(r);
        }

        return result;
    }

};
