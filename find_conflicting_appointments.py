
class Node:
    def __init__(self, start, end):
        self.start_time = start
        self.end_time = end
        self.left = None
        self.right = None


class Tree:
    def __init__(self):
        self.root = None

    def insertion(self, start, end):
        if start > end:
            return False

        node = Node(start, end)

        if self.root is None:
            self.root = node
        else:
            current = self.root

            while current is not None:
                if start <= current.start_time and end <= current.start_time:
                    if current.left is None:
                        current.left = node
                        break
                    else:
                        current = current.left

                elif start >= current.end_time and end >= current.end_time:
                    if current.right is None:
                        current.right = node
                        break
                    else:
                        current = current.right

                else:
                    conflicting.append((node, current))

                    if end >= current.end_time:
                        current = current.right
                    elif start <= current.start_time:
                        current = current.left
                    else:
                        break

    def inorder_single(self, root):
        if root is not None:
            self.inorder_single(root.left)
            print('[', root.start_time, 'to', root.end_time,']')
            self.inorder_single(root.right)

    def inorder(self):
        self.inorder_single(self.root)


tree = Tree()

conflicting = []

appointments = [ (10, 11), (8, 9), (12, 13), (12.2, 12.5), (8.5, 9.5), (2, 4), (10.5, 12.5), (3.5, 8.5) ]
#appointments = [ (1, 5), (3, 7), (2, 6), (10, 15), (5, 6), (4, 100) ]

print('Appointments: ')
for appointment in appointments:
    print('[', appointment[0], 'to', appointment[1], ']')
    tree.insertion(appointment[0], appointment[1])

print('\nConflicting appointments: ')
for appointment in conflicting:
    print('[', appointment[0].start_time, 'to', appointment[0].end_time, '] with [', appointment[1].start_time, 'to', appointment[1].end_time, ']')

