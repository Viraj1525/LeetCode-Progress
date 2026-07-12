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

    void preorder(TreeNode* root, vector<TreeNode*>& seq){
        if(root == NULL) return;
        seq.push_back(root);
        preorder(root->left, seq);
        preorder(root->right, seq);
    }

    void flatten(TreeNode* root) {
        if (root == NULL) return;

        vector<TreeNode*> seq;
        preorder(root, seq);

        int n = seq.size();

        for(int i=0; i<n-1; i++){
            seq[i]->left = NULL;
            seq[i]-> right = seq[i+1];
        }
        seq[n-1] -> right = NULL;
        seq[n-1] -> left = NULL;
    }
};