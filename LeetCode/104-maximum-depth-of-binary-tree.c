int max(int x, int y){
    return x > y ? x : y;
}
int maxDepth(struct TreeNode* root) {
    return root ? (1+max(maxDepth(root->left), maxDepth(root->right))) : 0;
}
