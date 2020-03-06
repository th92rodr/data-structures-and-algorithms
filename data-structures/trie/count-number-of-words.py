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

    def number_of_words(self):
        self.total = 0
        self.number_of_words_single(self.root)
        return self.total

    def number_of_words_single(self, current):
        while current is not None:
            if current.isEndOfWord:
                self.total = self.total + 1

            for key, child in current.children.items():
                self.number_of_words_single(child)
            current = None

trie = Trie()

words = ["the", "a", "there", "answer", "any", "by", "bye", "their"]
for word in words:
    trie.insertion(word)

print('Total number of words:', trie.number_of_words())
