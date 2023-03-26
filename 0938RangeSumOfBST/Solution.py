
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def calSum(self, root, low, high):
        if root == None:
            return 0
        if root.val >= low and root.val <= high:
            return root.val + self.calSum(root.left, low, high) + self.calSum(root.right, low, high)
        elif root.val < low:
            return self.calSum(root.right, low, high)
        else:
            return self.calSum(root.left, low, high)
            

    def rangeSumBST(self, root, low: int, high: int) -> int:
        return self.calSum(root, low, high)