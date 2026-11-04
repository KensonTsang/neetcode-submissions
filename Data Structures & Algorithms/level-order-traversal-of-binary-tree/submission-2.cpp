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

        if (root == nullptr) {
            return {};
        }

        queue<TreeNode*> q{};
        vector<vector<int>> result{};
        q.push(root);

        while (q.size() > 0) {
            int num = q.size();

            vector<int> temp{};

            for (int i = 0 ; i < num ; ++i) {
                auto* treeNode = q.front();
                q.pop();
                temp.push_back(treeNode->val);

                if (treeNode->left != nullptr) {
                    q.push(treeNode->left);
                }

                if (treeNode->right != nullptr) {
                    q.push(treeNode->right);
                }

            }

            result.push_back(temp);

        }

        return result;

    }
};
