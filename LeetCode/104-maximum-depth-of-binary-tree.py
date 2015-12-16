#!/usr/bin/env python
#coding=utf-8

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        return self.dfs(root)
        
    def dfs(self, root):
        if(root == None):
            return 0
        return 1 + max(self.dfs(root.left), self.dfs(root.right))
