```
# when initializing 2d matrix
mat = [[0] * 10] * 10                 # this is wrong!!
mat = [[0] * 10 for i in range(10)]
mat[0][0] = 1
print(m)
```