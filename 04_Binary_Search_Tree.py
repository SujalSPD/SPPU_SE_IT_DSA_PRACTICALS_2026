
import copy

class Node:
    def __init__(self, data):
        self.data = data
        self.left = self.right = None

# Insert a new node (ignore duplicates)
def insert(root, x):
    if root is None:
        return Node(x)
    if x < root.data:
        root.left = insert(root.left, x)
    elif x > root.data:
        root.right = insert(root.right, x)
    return root

# Delete a node from BST
def delete(root, x):
    if root is None:
        return None
    if x < root.data:
        root.left = delete(root.left, x)
    elif x > root.data:
        root.right = delete(root.right, x)
    else:
        if root.left is None:
            return root.right
        if root.right is None:
            return root.left

        # Find smallest node in right subtree
        temp = root.right
        while temp.left:
            temp = temp.left
        root.data = temp.data
        root.right = delete(root.right, temp.data)
    return root

# Search for a value
def search(root, x):
    if root is None:
        return False
    if root.data == x:
        return True
    if x < root.data:
        return search(root.left, x)
    return search(root.right, x)

# Display tree using inorder traversal
def inorder(root):
    if root:
        inorder(root.left)
        print(root.data, end=" ")
        inorder(root.right)

# Find maximum depth of tree
def depth(root):
    if root is None:
        return 0
    return 1 + max(depth(root.left), depth(root.right))

# Display mirror without changing original tree
def mirror(root):
    if root:
        mirror(root.left)
        mirror(root.right)
        root.left, root.right = root.right, root.left

# Display parent nodes and their children
def parents(root):
    if root:
        if root.left or root.right:
            print(root.data, "->",
                  root.left.data if root.left else None,
                  root.right.data if root.right else None)
        parents(root.left)
        parents(root.right)

# Display leaf nodes (nodes without children)
def leaves(root):
    if root:
        if not root.left and not root.right:
            print(root.data, end=" ")
        leaves(root.left)
        leaves(root.right)

# Display nodes level by level
def levelwise(root):
    if root is None:
        print("Tree is empty")
        return
    q = [root]
    while q:
        node = q.pop(0)
        print(node.data, end=" ")
        if node.left:
            q.append(node.left)
        if node.right:
            q.append(node.right)

# Main program
root = None

while True:
    print("\n\n1.Insert  2.Delete  3.Search  4.Traversal")
    print("5.Depth   6.Mirror  7.Copy    8.Parent-Child")
    print("9.Leaves  10.Level Wise  0.Exit")

    ch = int(input("Enter choice: "))

    if ch == 1:
        x = int(input("Enter value: "))
        root = insert(root, x)

    elif ch == 2:
        x = int(input("Enter value: "))
        root = delete(root, x)

    elif ch == 3:
        x = int(input("Enter value: "))
        print("Found" if search(root, x) else "Not Found")

    elif ch == 4:
        inorder(root)

    elif ch == 5:
        print("Depth:", depth(root))

    elif ch == 6:
        temp = copy.deepcopy(root)
        mirror(temp)
        inorder(temp)

    elif ch == 7:
        temp = copy.deepcopy(root)
        print("Copy created:")
        inorder(temp)

    elif ch == 8:
        parents(root)

    elif ch == 9:
        leaves(root)

    elif ch == 10:
        levelwise(root)

    elif ch == 0:
        break

    else:
        print("Invalid choice")
