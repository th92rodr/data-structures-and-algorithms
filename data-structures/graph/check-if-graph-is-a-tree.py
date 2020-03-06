'''
An undirected graph is a tree if:
 - There is no cycle.
 - The graph is connected.
'''

import queue

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class RootNode:
    def __init__(self, data):
        self.data = data
        self.root = None
        self.next = None

    def insert_node(self, data):
        node = Node(data)

        if self.root is None:
            self.root = node

        else:
            current = self.root
            while current.next is not None:
                current = current.next
            current.next = node

class Graph:
    def __init__(self):
        self.head = None

    def add_edge(self, source, dest):
        if self.head is None:
            root_node = RootNode(source)
            self.head = root_node
            root_node.insert_node(dest)

        else:
            current = self.head
            while current is not None:
                if current.data == source:
                    current.insert_node(dest)
                    return
                last = current
                current = current.next

            root_node = RootNode(source)
            last.next = root_node
            root_node.insert_node(dest)

    def print_graph(self):
        current_root = self.head
        while current_root is not None:
            print("|% 2d | ->" %(current_root.data), end = '')
            current_node = current_root.root
            while current_node is not None:
                print("% 2d ->" %(current_node.data), end = '')
                current_node = current_node.next

            current_root = current_root.next
            print(" NULL")

    def is_a_tree(self):
        # create a hash to mark the visited nodes
        visited = set()

        # create a queue to store the next nodes to be visited
        q = queue.Queue()
        q.put(self.head.data)

        # check if there is a cycle in the graph
        while q.empty() is False:
            # get the next node to be visited and mark it as visited
            node = q.get()
            visited.add(node)

            # find the node
            current = self.head
            while current is not None:
                if current.data == node:
                    # get the current node neighbors
                    current_node = current.root
                    while current_node is not None:

                        # check if the node has already been visited
                        # checking for cycle
                        if current_node.data in visited:
                            return False

                        # put the current node neighbors in the queue
                        q.put(current_node.data)

                        current_node = current_node.next
                    break

                else:
                    current = current.next

        # check if the hole graph is connected
        current = self.head
        while current is not None:
            # if the current node has not been visited then
            # the graph is not connected
            if current.data not in visited:
                return False
            current = current.next

        return True


graph = Graph()

graph.add_edge(0, 1)
graph.add_edge(1, 2)
graph.add_edge(1, 4)
graph.add_edge(2, 3)
print("Graph 1: ")
graph.print_graph()

if graph.is_a_tree(): print("Graph 1 is a Tree")
else: print("Graph 1 is not a Tree")


graph1 = Graph()

graph1.add_edge(1, 0)
graph1.add_edge(0, 2)
graph1.add_edge(0, 3)
graph1.add_edge(2, 1)
graph1.add_edge(3, 4)
print("\nGraph 2: ")
graph1.print_graph()

if graph1.is_a_tree(): print("Graph 2 is a Tree")
else: print("Graph 2 is not a Tree")
