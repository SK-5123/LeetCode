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
    void flatten(TreeNode* root) {
        if (!root) return;
        flattenHelper(root);
    }
    
    TreeNode* flattenHelper(TreeNode* node) {
        if (!node) return nullptr;
        
        TreeNode* rightChild = node->right;
        TreeNode* leftEnd = flattenHelper(node->left);
        TreeNode* rightEnd = flattenHelper(rightChild);
        
        if (leftEnd) {
            leftEnd->right = rightChild;
            node->right = node->left;
            node->left = nullptr;
        }
        
        return rightEnd ? rightEnd : (leftEnd ? leftEnd : node);
    }
};
