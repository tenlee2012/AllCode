public class Solution {
    public int maxDepth(TreeNode root) {
        return dfs(root);
    }
    private int dfs(TreeNode root){
        if(root == null) return 0;
        return 1 + Math.max(dfs(root.left), dfs(root.right));
    }
}
