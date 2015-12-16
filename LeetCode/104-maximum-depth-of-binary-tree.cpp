class Solution {
public:
    int maxDepth(TreeNode* root) {
        return dfs(root);
    }
private:
    int dfs(TreeNode*root){
        if(root == NULL) return 0;
        return 1 + max(dfs(root->left), dfs(root->right));
    }
};
