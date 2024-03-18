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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorder_index_map;
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_index_map[inorder[i]] = i;
        }
        return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inorder_index_map);
    }

    TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd, 
                              vector<int>& inorder, int inStart, int inEnd, 
                              unordered_map<int, int>& inorder_index_map) {
        if (preStart > preEnd || inStart > inEnd) return nullptr;

        int rootValue = preorder[preStart];
        TreeNode* root = new TreeNode(rootValue);

        int rootIndexInInorder = inorder_index_map[rootValue];
        int leftSubtreeSize = rootIndexInInorder - inStart;

        root->left = buildTreeHelper(preorder, preStart + 1, preStart + leftSubtreeSize, 
                                     inorder, inStart, rootIndexInInorder - 1, inorder_index_map);
        root->right = buildTreeHelper(preorder, preStart + leftSubtreeSize + 1, preEnd, 
                                      inorder, rootIndexInInorder + 1, inEnd, inorder_index_map);

        return root;
    }
};