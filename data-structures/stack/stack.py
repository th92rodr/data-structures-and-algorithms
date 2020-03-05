class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Stack:
    def __init__(self):
        self.root = None

    def push(self, data):
        newNode = Node(data)
        newNode.next = self.root
        self.root = newNode

    def pop(self):
        if self.root is not None:
            temp = self.root
            self.root = temp.next
            return temp.data
        return None

    def top(self):
        if self.root is not None:
            return self.root.data
        return None


stack = Stack()
stack.push(10)
stack.push(20)
stack.push(30)

print('Popped ', stack.pop())
print('Top ', stack.top())
