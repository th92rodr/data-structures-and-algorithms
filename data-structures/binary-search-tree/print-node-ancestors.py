class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

class Tree:
    def __init__(self):
        self.root = None

    def insertion(self, key):
        node = Node(key)

        if self.root is None:
            self.root = node
        else:
            current = self.root

            while current is not None:
                if key > current.key:
                    if current.right is None:
                        current.right = node
                        break
                    else:
                        current = current.right
                else:
                    if current.left is None:
                        current.left = node
                        break
                    else:
                        current = current.left

    def delete(self, key):
        if self.root is not None:
            current = self.root

            while current is not None:
                # key is greater than current - go right
                if key > current.key:
                    last = current
                    current = current.right
                    to_right = True

                # key is lesser than current - go left
                elif key < current.key:
                    last = current
                    current = current.left
                    to_right = False

                # key is equal
                else:

                    # current node has no child
                    if current.left is None and current.right is None:
                        if to_right:
                            last.right = None
                        else:
                            last.left = None

                    # current node has only left child
                    elif current.left is not None and current.right is None:
                        if to_right:
                            last.right = current.left
                        else:
                            last.left = current.left

                    # current node has only right child
                    elif current.left is None and current.right is not None:
                        if to_right:
                            last.right = current.right
                        else:
                            last.left = current.right

                    # current node has both children
                    else:
                        # find the minimum value in the current node right subtree
                        minor = current.right
                        while minor and minor is not None:
                            minor = minor.left

                        # replace current with minor node key
                        current.key = minor.key

                        # delete the minor node found
                        self.delete(minor.key)

                    break

    def search(self, key):
        if self.root is not None:
            current = self.root

            while current is not None:
                # key found
                if key is current.key:
                    return current.key

                # key is greater than current - go right
                elif key > current.key:
                    current = current.right

                # key is lesser than current - go left
                else:
                    current = current.left

        return None

    def inorder_single(self, root):
        if root is not None:
            self.inorder_single(root.left)
            print(root.key)
            self.inorder_single(root.right)

    def inorder(self):
        self.inorder_single(self.root)

    def print_ancestors(self, key):
        if self.root is not None:
            current = self.root
            path = []

            print('Node', key, 'ancestors: ')

            while current is not None:
                # key found
                if key is current.key:
                    print(path)
                    break

                # key is greater than current - go right
                elif key > current.key:
                    path.append(current.key)
                    current = current.right

                # key is lesser than current - go left
                else:
                    path.append(current.key)
                    current = current.left


tree = Tree()

tree.insertion(5)
tree.insertion(2)
tree.insertion(3)
tree.insertion(1)
tree.insertion(4)
tree.insertion(7)
tree.insertion(6)
tree.insertion(8)

'''''''''''''''''''''''
           5
         /   \
        /     \
       2       7
      / \     / \
     1   3   6   8
          \
           4
'''''''''''''''''''''''

tree.print_ancestors(8)
