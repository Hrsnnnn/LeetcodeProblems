import sys
sys.path.append("..")
import Utils.MyTree as tree
from typing import List, Union

class Solution:
    def calPathSum(self, root:tree.TreeNode) -> Union[int, int]:
        if root is None:
            return (-1000, -1000)
        if root.left is None and root.right is None:
            return (root.val, root.val)
        
        ml, Ml = self.calPathSum(root.left)
        mr, Mr = self.calPathSum(root.right)

        m = max(root.val, root.val + ml, root.val + mr)
        M = max(Ml, Mr, root.val + ml + mr, ml, mr)
        print(m, M, root.val, root.depth)
        return (m, M)

    def maxPathSum(self, root) -> int:
        res = self.calPathSum(root)
        return res

if __name__ == '__main__':
    sol = Solution()
    null = None
    arr = [5,4,8,11,null,13,4,7,2,null,null,null,1]
    root = tree.buildTree(arr)
    tree.bfsTree([root])
    res = sol.maxPathSum(root)
    print(res)
