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
    // Returns height if balanced, otherwise -1
    int checkHeight(TreeNode* root) {
        if (!root) return 0;
        int leftH = checkHeight(root->left);
        if (leftH == -1) return -1;      // left subtree is unbalanced
        int rightH = checkHeight(root->right);
        if (rightH == -1) return -1;     // right subtree is unbalanced
        
        if (abs(leftH - rightH) > 1) return -1;  // current node is unbalanced
        return 1 + max(leftH, rightH);           // return height
    }

    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};