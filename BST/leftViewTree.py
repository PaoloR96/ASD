import sys
 
 
# A class to store a binary tree node
class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

def leftv(root,level,maxlev,storeData):
    if root is None:
        return 
    if level>maxlev[0]:
        storeData.append(root.data)
        maxlev[0]=level
    leftv(root.left,level+1,maxlev,storeData)
    leftv(root.right,level+1,maxlev,storeData)



def LeftView(root):
    maxlev=[0]
    storeData=[]
    leftv(root,1,maxlev,storeData)
    return storeData
 
 
if __name__ == '__main__':
 
 
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.right = Node(4)
    root.right.left = Node(5)
    root.right.right = Node(6)
    root.right.left.left = Node(7)
    root.right.left.right = Node(8)
 
    print(LeftView(root))