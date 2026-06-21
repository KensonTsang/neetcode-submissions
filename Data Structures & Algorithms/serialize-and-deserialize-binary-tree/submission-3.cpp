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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // N or +/- Number

        if (root == nullptr) {
            return "N#";
        }

        stringstream ss;
        
        if (root->val >= 0) {
            ss << "+";
        };        

        ss << root->val;
        ss << "#";


        string leftStr = serialize(root->left);
        string rightStr = serialize(root->right);
        
        ss << leftStr << rightStr;

        return ss.str();
    }

    TreeNode* deserialize(string data, int& index) {

        if (data[index] == 'N') {
            index += 2;
            return nullptr;            
        }

        int val = 0;        
        bool isNegative = (data[index++] == '-');

        while(data[index] != '#') {                     
            val = (val * 10) + (data[index] - '0');                         
            index++;
        }
        
        if (isNegative) val *= -1;
        auto* root = new TreeNode(val);


        index++;
        root->left = deserialize(data, index);        
        root->right = deserialize(data, index);

        return root;

    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        return deserialize(data, index);
    }
};
