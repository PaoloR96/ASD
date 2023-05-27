import sys
 
 
# A class to store a binary tree node
class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right
 
def findMaxSumPath(root, max_sum=-sys.maxsize):
 
    
    if root is None:
        return 0, max_sum
    left, max_sum = findMaxSumPath(root.left, max_sum)
    right, max_sum = findMaxSumPath(root.right, max_sum)
    # case 1: left child is None
    if root.left is None:
        return (right + root.data), max_sum
    # case 2: right child is None
    if root.right is None:
        return (left + root.data), max_sum
    # find the maximum sum path "through" the current node
    cur_sum = left + right + root.data
    max_sum = max(cur_sum, max_sum)
    # case 3: both left and right child exists
    return (max(left, right) + root.data), max_sum
 
 
if __name__ == '__main__':
 
 
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.right = Node(-4)
    root.right.left = Node(5)
    root.right.right = Node(6)
    root.right.left.left = Node(7)
    root.right.left.right = Node(8)
 
    print(findMaxSumPath(root)[1])