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
    // Collect values in sorted order
    void inorder(TreeNode* root, vector<int>& vals) {
        if (!root) return;
        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }

    // Build balanced BST from sorted values [l..r]
    TreeNode* buildBalanced(vector<int>& vals, int l, int r) {
        if (l > r) return nullptr;
        int mid = (l + r) / 2;
        TreeNode* node = new TreeNode(vals[mid]);
        node->left = buildBalanced(vals, l, mid - 1);
        node->right = buildBalanced(vals, mid + 1, r);
        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vals;
        inorder(root, vals);
        return buildBalanced(vals, 0, vals.size() - 1);
    }
};