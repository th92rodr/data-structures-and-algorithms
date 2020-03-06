class Node:
    def __init__(self, data):
        self.data = data
        # pointer to the next node
        self.next = None

class RootNode:
    def __init__(self, data):
        self.data = data
        # pointer to the first node
        self.root = None
        # pointer to the next root node
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

    def delete_all_nodes(self):
        self.root = None

    def delete_single_node(self, data):
        if self.root is not None:
            current = self.root
            is_first = True

            while current is not None:
                if current.data == data:
                    if is_first:
                        self.root = current.next
                    else:
                        last.next = current.next
                    break

                else:
                    last = current
                    current = current.next
                    is_first = False

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
                    # root node already exists
                    current.insert_node(dest)
                    return
                last = current
                current = current.next

            root_node = RootNode(source)
            last.next = root_node
            root_node.insert_node(dest)

    def delete_edge(self, source, dest):
        current = self.head
        while current is not None:
            if current.data == source:
                current.delete_single_node(dest)
                break

            current = current.next

    def delete_root_node(self, data):
        if self.head is not None:
            current = self.head
            is_first = True

            while current is not None:
                if current.data == data:
                    if is_first:
                        self.head = current.next
                    else:
                        last.next = current.next

                    current.delete_all_nodes()
                    break

                else:
                    last = current
                    current = current.next
                    is_first = False

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

    def get_number_of_edges(self):
        edges = 0
        current_root = self.head
        while current_root is not None:
            current_node = current_root.root
            while current_node is not None:
                edges += 1
                current_node = current_node.next

            current_root = current_root.next
        return edges


graph = Graph()
graph.add_edge(1, 2)
graph.add_edge(1, 4)
graph.add_edge(1, 6)
graph.add_edge(2, 1)
graph.add_edge(2, 3)
graph.add_edge(2, 5)
graph.add_edge(3, 10)
graph.add_edge(3, 20)
graph.add_edge(3, 30)
graph.add_edge(4, 1)
graph.add_edge(4, 2)
graph.add_edge(4, 3)
graph.print_graph()

print("Number of edges: ", graph.get_number_of_edges())
