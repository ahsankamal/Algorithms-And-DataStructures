# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class BinaryTree:
    def __init__(self):
        self.root = None
        self.height = 0
        self.deepest_leaves_sum = 0

    def depth(self, root, current_height):
        if current_height > self.height:
            self.height = current_height
            self.deepest_leaves_sum = root.val
        elif current_height == self.height:
            self.deepest_leaves_sum += root.val

        if root.left != None:
            self.depth(root.left, current_height+1)
        if root.right != None:
            self.depth(root.right, current_height+1)
            
class Solution:
    def deepestLeavesSum(self, root: TreeNode) -> int:
        bt = BinaryTree()
        bt.root = root
        bt.depth(bt.root, 1)
        return bt.deepest_leaves_sum
        
