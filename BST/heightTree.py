class Node:

	
	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None

def maxDepth(node):
	if node is None:
		return 0

	else:
		lDepth = maxDepth(node.left)
		rDepth = maxDepth(node.right)
		if (lDepth > rDepth):
			return lDepth+1
		else:
			return rDepth+1


def InsNodo(radice, valore):
    
    if radice is None:
        return Node(valore)
    if valore < radice.valore:
        radice.left = InsNodo(radice.left, valore)
    if valore > radice.valore:
        radice.right = InsNodo(radice.right, valore)
    return radice


# Driver Code
if __name__ == '__main__':

    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)


    print("L'altezza e' %d" % (maxDepth(root)))


