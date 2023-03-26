## 数据结构

### Hash

#### Hash Concept

Hash碰撞

### Queue

#### Deque

双端队列

### Binary Tree

#### get Height and Depth

dfs recursion method

```python
def getHeightAndDepth(self, node, depth):
        if node is None:
            return -1
        self.num2depth[node.val] = depth
        h = max(self.getHeightAndDepth(node.left, depth+1), self.getHeightAndDepth(node.right, depth+1)) + 1
        self.num2height[node.val] = h
        return h
```
