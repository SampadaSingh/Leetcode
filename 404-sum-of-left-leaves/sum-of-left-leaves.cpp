/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
public:
    bool isLeaf(TreeNode* node) {
        return node != nullptr && node->left == nullptr &&
               node->right == nullptr;
    }

    int sumOfLeftLeaves(TreeNode* root, bool isLeft = false) {
        if (root == nullptr) {
            return 0;
        }
        // If it's a leaf node and it's a left child, return its value
        if (isLeaf(root) && isLeft) {
            return root->val;
        }
        // Recursively calculate the sum of left leaves in both left and right
        // subtrees
        return sumOfLeftLeaves(root->left, true) +
               sumOfLeftLeaves(root->right, false);
    }
};