from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None, depth=0) -> None:
        self.val = val
        self.left = left
        self.right = right
        self.depth = depth
    
    def __str__(self) -> str:
        return "TreeNode:" + self.val

def buildTree(arr:List, idx, depth=0):
    if idx >= len(arr):
        return None
    if arr[idx] == None:
        return None
    node = TreeNode(arr[idx])
    node.left = buildTree(arr, 2 * idx + 1, depth+1)
    node.right = buildTree(arr, 2 * idx + 2, depth+1)
    node.depth = depth

    return node

def buildTree(arr:List[int]):
    q = []
    for a in arr:
        t = TreeNode(a)
        q.append(t)
    buildTreeLeetCode(q[0:1], q[1:])
    return q[0]

def buildTreeLeetCode(parents:List[TreeNode], q:List[TreeNode]):
    if len(q) == 0:
        return
    if len(q) == 1:
        p = parents[0]
        p.left = q[0]
        return

    p = parents[0]
    p.left = q[0] if q[0].val is not None else None
    p.right = q[1] if q[1].val is not None else None
    if q[0].val is not None:
        parents.append(q[0])
    if q[1].val is not None:
        parents.append(q[1])
    buildTreeLeetCode(parents[1:], q[2:])
    return

def MyPrint(x:TreeNode):
    print(x.val, end=' ')
    if x.left is None:
        print('left:None', end=' ')
    else:
        print('left:', x.left.val, end=' ', sep='')
    if x.right is None:
        print('right:None')
    else:
        print('right:', x.right.val, sep='')

def bfsTree(q:List[TreeNode], traverse=MyPrint):
    if len(q) == 0:
        return print("bfs over")
    if q[0] == None:
        return bfsTree(q[1:])

    traverse(q[0])
    q.append(q[0].left)
    q.append(q[0].right)
    bfsTree(q[1:])

if __name__ == "__main__":
    null = None
    arr = [5,4,8,11,null,13,4,7,2,null,null,null,1]
    node = buildTree(arr)
    bfsTree([node])
