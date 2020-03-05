class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.root = None

    def insert_at_end(self, data):
        new_node = Node(data)

        if self.root is None:
            self.root = new_node
        else:
            current = self.root
            while current.next is not None:
                current = current.next
            current.next = new_node

    def add_loop_on_purpose(self, data):
        new_node = Node(data)
        new_node.next = self.root

        current = self.root
        while current.next is not None:
            current = current.next
        current.next = new_node

    def detect_loop(self):
        hash = set()
        current = self.root
        while current is not None:
            if current in hash:
                return True

            hash.add(current)
            current = current.next

        return False

    def print_list(self):
        current = self.root
        while current is not None:
            print(current.data, " -> ")
            current = current.next


def create_list():
    list = LinkedList()
    i = 1
    while i < 10:
        list.insert_at_end(i)
        i += 1
    return list

def create_list_with_loop():
    list = LinkedList()
    i = 1
    while i < 10:
        list.insert_at_end(i)
        i += 1
    list.add_loop_on_purpose(i)
    return list


list1 = create_list()
list2 = create_list_with_loop()

if list1.detect_loop(): print("There is a loop in list 1\n")
else: print("There isn't a loop in list 1\n")

if list2.detect_loop(): print("There is a loop in list 2\n")
else: print("There isn't a loop in list 2\n")
