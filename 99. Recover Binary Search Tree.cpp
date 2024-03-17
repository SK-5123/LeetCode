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
    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* prev = nullptr;
        
        function<void(TreeNode*)> inorderTraversal = [&](TreeNode* node) {
            if (node == nullptr) return;
            
            inorderTraversal(node->left);
            
            if (prev != nullptr && prev->val >= node->val) {
                if (first == nullptr) {
                    first = prev;
                }
                second = node;
            }
            prev = node;
            
            inorderTraversal(node->right);
        };
        
        inorderTraversal(root);
        
        if (first != nullptr && second != nullptr) {
            swap(first->val, second->val);
        }
    }
};
