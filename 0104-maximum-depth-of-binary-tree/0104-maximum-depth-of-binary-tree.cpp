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

    int ans = 1;

    void preorder(TreeNode* root, int height){
        if(root == NULL) {
            ans = max(height,ans);
            height = 0;
            return;
        }
        height++;
        preorder(root->left, height);
        preorder(root->right, height);
    }

    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int height = 0;
        preorder(root, height);
        return ans;
    }
};