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

    def breadth_first_search(self, start_node):
        # create a hash to mark the visited nodes
        visited = set()

        # create a queue to store the next nodes to be visited
        q = queue.Queue()
        q.put(start_node)

        print("% 2d ->" %(start_node), end = '')

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
                        # put the current node neighbors which weren't visited yet in the queue
                        if current_node.data not in visited:
                            print("% 2d ->" %(current_node.data), end = '')
                            q.put(current_node.data)

                        current_node = current_node.next
                    break

                else:
                    current = current.next
        print('')


graph = Graph()

graph.add_edge(0, 1)
graph.add_edge(0, 2)
graph.add_edge(1, 2)
graph.add_edge(2, 0)
graph.add_edge(2, 3)
graph.add_edge(3, 3)


print("Breadth First Search: ")
graph.breadth_first_search(2)
