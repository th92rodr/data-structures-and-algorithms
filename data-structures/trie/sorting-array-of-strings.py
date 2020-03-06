class Node:
    def __init__(self, key):
        self.key = key
        self.children = {}
        # isEndOfWord is True if node represent the end of a word
        self.isEndOfWord = False

class Trie:
    def __init__(self):
        self.root = Node('')

    def insertion(self, key):
        key.lower()
        current = self.root

        for char in key:
            if char not in current.children:
                node = Node(char)
                current.children[char] = node
            current = current.children[char]
            node = current

        node.isEndOfWord = True

    def search(self, key):
        key.lower()
        current = self.root

        for char in key:
            if char not in current.children:
                return False
            else:
                current = current.children[char]
        return True

    def sort_array(self, array):
        for word in array:
            self.insertion(word)
        self.sorted_array = []
        self.preorder(self.root, '')
        return self.sorted_array

    def preorder(self, current, prefix):
        alphabet = ['a','b','c','d','e','f','g','h','i','j','k','l',
        'm','n','o','p','q','r','s','t','u','v','w','x','y','z']

        while current is not None:
            if current.isEndOfWord:
                self.sorted_array.append(prefix + current.key)
            prefix = prefix + current.key

            for letter in alphabet:
                if letter in current.children:
                    self.preorder(current.children[letter], prefix)
            current = None


trie = Trie()

array = ["geeks", "for", "geeks", "a", "portal", 
        "to", "learn", "can", "be", "computer", 
        "science", "zoom", "yup", "fire", "in", "data"]

print('Array:\n', array)
print('Sorted array:\n', trie.sort_array(array))
