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

    def shortest_path(self, source, dest):
        # dictionary to store the distances to all the nodes from the source node
        distances = {}
        distances[source] = 0

        # dictionary to store the predecessores of each node
        pred = {}

        # create a hash to mark the visited nodes
        visited = set()

        # create a queue to store the next nodes to be visited
        q = queue.Queue()
        q.put(source)

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

                        # if the current node is not yet in the dictionary
                        # or it current value in the dict is greater than the new value
                        # update the distances dict
                        if current_node.data not in distances or \
                        distances[current_node.data] > distances[current.data] + 1:
                            distances[current_node.data] = distances[current.data] + 1
                            pred[current_node.data] = current.data

                       # put the current node neighbors which weren't visited yet in the queue
                        if current_node.data not in visited:
                            q.put(current_node.data)

                        current_node = current_node.next
                    break

                else:
                    current = current.next

        # find the path between source and destination by the predecessores dict
        path = []
        path.append(dest)
        x = pred[dest]
        while x is not source:
            path.append(x)
            x = pred[x]
        path.append(source)

        path.reverse()

        return path, distances[dest]


graph = Graph()

graph.add_edge(0, 1)
graph.add_edge(0, 3)
graph.add_edge(1, 2)
graph.add_edge(3, 4)
graph.add_edge(3, 7)
graph.add_edge(4, 5)
graph.add_edge(4, 6)
graph.add_edge(4, 7)
graph.add_edge(5, 6)
graph.add_edge(6, 7)

graph.print_graph()
print('')

print('Path between node 0 and 7: ', graph.shortest_path(0, 7))
