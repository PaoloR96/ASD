class Node:
     
    # Constructor to create a new node
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
        
def IsBST(root):
    if root ==None:
        return True;
    if(root.left and root.data < root.left.data):
        return False
    if(root.right and root.data > root.right.data):
        return False
    return IsBST(root.left) and IsBST(root.right)
    
    


# Driver code
if __name__ == "__main__":
  root = Node(9)
  
  root.left = Node(5)
  root.right = Node(10)
  
  root.left.left = Node(4)
  root.left.right = Node(9)
  
  root.right.left= Node(8)
  root.right.right= Node(18)
  # Function call
  if (IsBST(root)):
      print("E un albero BST")
  else:
      print("Non è un albero BST")
