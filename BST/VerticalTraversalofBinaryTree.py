import sys
 
 
# A class to store a binary tree node
class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

def verticalOrder(root): 
        #Your code here
        q = []
        levels = [defaultdict(list)]
        q.append([root, 0])
        while (q):
            node, vlevel = q.pop(0)
            levels[vlevel].append(node.data)
            if (node.left):
                q.append([node.left, vlevel-1])
            if (node.right):
                q.append([node.right, vlevel+1])
        vTrav = []
        levs = sorted(levels.keys())
        for lev in levs:
            vTrav.extend(levels[lev])
        return vTrav
 
 
if __name__ == '__main__':
 
 
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.right = Node(4)
    root.right.left = Node(5)
    root.right.right = Node(6)
    root.right.left.left = Node(7)
    root.right.right.right = Node(8)
 
    print(verticalOrder(root))