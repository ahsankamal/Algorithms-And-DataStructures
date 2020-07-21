# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def constructBST(self, preorder, root, start, end):
        root = TreeNode(val=preorder[start])
        # print(root.val, start, end)
        no_greater_element_to_the_right=True
        for i in range(start, end+1):
            if preorder[start] < preorder[i]:
                no_greater_element_to_the_right=False
                break

        if start==end:
            return root

        if no_greater_element_to_the_right == False:
            if i - 1 > start :
                root.left = self.constructBST(preorder, root.left, start + 1, i - 1)
            if i - 1 <= end:
                root.right = self.constructBST(preorder, root.right, i , end)
        else:
            root.left = self.constructBST(preorder, root.left, start + 1, end)

        return root

    def dfs(self, root):
        print(root.val)
        if root.left != None:
            self.dfs(root.left)
        if root.right != None:
            self.dfs(root.right)
            
    def bstFromPreorder(self, preorder):
        n = len(preorder)
        root = self.constructBST(preorder, None, 0, n - 1)
        self.dfs(root)
        return root
    
    
