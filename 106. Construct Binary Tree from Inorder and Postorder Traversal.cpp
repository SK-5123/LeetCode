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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorder_map;
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_map[inorder[i]] = i;
        }
        
        return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1, inorder_map);
    }
    
private:
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int in_start, int in_end, int post_start, int post_end, unordered_map<int, int>& inorder_map) {
        if (in_start > in_end || post_start > post_end) {
            return nullptr;
        }
        
        int root_val = postorder[post_end];
        TreeNode* root = new TreeNode(root_val);
        
        int root_index = inorder_map[root_val];
        
        root->left = buildTreeHelper(inorder, postorder, in_start, root_index - 1, post_start, post_start + root_index - in_start - 1, inorder_map);
        root->right = buildTreeHelper(inorder, postorder, root_index + 1, in_end, post_start + root_index - in_start, post_end - 1, inorder_map);
        
        return root;
    }
};