import sys
from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None, depth=0):
        self.val = val
        self.left = left
        self.right = right
        self.depth = depth

class Solution:
    def __init__(self) -> None:
        self.subsums = []
        
    def buildTree(self, arr, idx, depth=0):
        if idx >= len(arr) or arr[idx] == None:
            return None
        node = TreeNode(arr[idx])
        node.left = self.buildTree(arr, 2*idx+1, depth+1)
        node.right = self.buildTree(arr, 2*idx+2, depth+1)
        node.depth = depth
        return node
    
    def calSum(self, root:TreeNode):
        if root is None:
            return 0
        if root.left is None and root.right is None:
            self.subsums.append(root.val)
            return root.val
        s = root.val + self.calSum(root.left) + self.calSum(root.right)
        self.subsums.append(s)
        return s
    
    def displayTree(self, q:List[TreeNode]):
        if len(q) == 0:
            return print("display over")
        if q[0] == None:
            return self.displayTree(q[1:])

        print(q[0].val, q[0].depth)
        q.append(q[0].left)
        q.append(q[0].right)
        self.displayTree(q[1:])

    def maxProduct(self, root):
        allsum = self.calSum(root)
        res = 0
        for s in self.subsums:
            res = max(res, (allsum - s) * s)
        return res

if __name__ == "__main__":
    sol = Solution()
    arr = [1, 2, 3, 4, 5, 6]
    root = sol.buildTree(arr, 0, 0)
    sol.displayTree([root])
    res = sol.maxProduct(root)
    print(res)
