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
    int kthSmallest(TreeNode* root, int k) {
        int result = 0;
        int count = 0;
        dfs(root, k, count, result);
        return result;
    }
    void dfs(TreeNode *root, int k, int& count, int& result){

        if(!root) return;
        dfs(root->left, k, count, result);
        if(count == k-1) result=root->val;
        count++;
        dfs(root->right, k, count, result);

    }
};
