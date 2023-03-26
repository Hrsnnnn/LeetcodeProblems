import sys
sys.path.append("..")
import Utils.MyTree as MyTree
from typing import List, Optional, Union

class TreeNode:
    def __init__(self, val=0, left=None, right=None, depth=0) -> None:
        self.val = val
        self.left = left
        self.right = right
    
    def __str__(self) -> str:
        return "TreeNode:" + self.val

class Solution:
    def __init__(self) -> None:
        self.depth = 0
        self.ans_dict = {}
        self.depthDict = {}
        self.num2depth = {}
        self.num2height = {}

    def treeQueries_slow(self, root: Optional[TreeNode], queries: List[int]) -> List[int]:
        ans = []
        for q in queries:
            self.depth = 0
            if self.ans_dict.keys().__contains__(q):
                ans.append(self.depth)
            else:
                self.bfsTree([(root, 0)], q)
                ans.append(self.depth)
                self.ans_dict.update({q:self.depth})
        return ans
    
    def getDepthDict(self, q):
        if len(q) == 0:
            return None
        if q[0][0] == None:
            return self.getDepthDict(q[1:])

        # traverse
        if self.depthDict.keys().__contains__(q[0][1]):
            self.depthDict[q[0][1]].append(q[0][0].val)
        else:
            self.depthDict.update({q[0][1]:[q[0][0].val]})
        
        if not self.num2depth.keys().__contains__(q[0][0].val):
            self.num2depth.update({q[0][0].val:q[0][1]})
        
        q.append((q[0][0].left, q[0][1]+1))
        q.append((q[0][0].right, q[0][1]+1))
        self.getDepthDict(q[1:])

    def getHeightDict(self, root):
        if root == None:
            return -1
        if root.left == None and root.right == None:
            self.num2height.update({root.val:0})
            return 0
        else:
            height = max(self.getHeightDict(root.left), self.getHeightDict(root.right)) + 1
            self.num2height.update({root.val:height})
            return height
    
    def getHeightAndDepth(self, node, depth):
        if node is None:
            return -1
        self.num2depth[node.val] = depth
        h = max(self.getHeightAndDepth(node.left, depth+1), self.getHeightAndDepth(node.right, depth+1)) + 1
        self.num2height[node.val] = h
        return h

    def treeQueries(self, root: Optional[TreeNode], queries: List[int]) -> List[int]:
        self.getHeightAndDepth(root, 0)
        print('depth:', self.num2depth)
        print('height:', self.num2height)
        depth2maxlength = {}
        
        for num in self.num2depth.keys():
            d, h = self.num2depth[num], self.num2height[num]
            if not depth2maxlength.keys().__contains__(d):
                depth2maxlength.update({d:[d+h]})
            else:
                depth2maxlength[d].append(d+h)
            depth2maxlength[d].sort(reverse=True)
            if len(depth2maxlength) > 2:
                depth2maxlength[d] = depth2maxlength[d][:2]
        print(depth2maxlength)
        
        ans = []
        self.ans_dict = {}
        for q in queries:
            if self.ans_dict.keys().__contains__(q):
                ans.append(self.ans_dict[q])
            else:
                d = self.num2depth[q]
                maxlength = depth2maxlength[d]
                if len(maxlength) == 1:
                    ans.append(self.num2depth[q] - 1)
                elif self.num2depth[q] + self.num2height[q] == maxlength[0]:
                    ans.append(max(maxlength[1], self.num2depth[q]-1))
                else:
                    ans.append(maxlength[0])
                self.ans_dict.update({q:ans[-1]})
        
        return ans

    def bfsTree(self, q:List[Union[TreeNode, int]], val):
        if len(q) == 0:
            return print("bfs over")
        if q[0][0] == None:
            return self.bfsTree(q[1:], val)

        # traverse
        for node in q:
            if node[0] is None:
                print("TreeNode:", "None", "|", node[1], end=' ')
            else:
                print("TreeNode:", node[0].val, "|", node[1], end=' ')

        if q[0][0].val == val:
            return self.bfsTree(q[1:], val)
        
        self.depth = max(self.depth, q[0][1])
        print(' - ', self.depth)
        
        q.append((q[0][0].left, q[0][1]+1))
        q.append((q[0][0].right, q[0][1]+1))
        self.bfsTree(q[1:], val)

if __name__ == '__main__':
    null = None
    testcases = [
        ([1,3,4,2,null,6,5,null,null,null,null,null,7], [4]),
        # ([1,null,5,3,null,2,4], [3,5,4,2,4])
    ]
    for t in testcases:
        tree = MyTree.buildTree(t[0])
        MyTree.bfsTree([tree])
        print('Query:', t[1])
        sol = Solution()
        res = sol.treeQueries(tree, t[1])
        print(res)
