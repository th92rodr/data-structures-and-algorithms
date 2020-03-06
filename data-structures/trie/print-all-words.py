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

    def all_words(self):
        self.all_words_single(self.root, '')

    def all_words_single(self, current, prefix):
        while current is not None:
            if current.isEndOfWord:
                print('{0}{1}'.format(prefix, current.key))
            prefix = prefix + current.key

            for key, child in current.children.items():
                self.all_words_single(child, prefix)
            current = None

trie = Trie()

words = ["the", "a", "there", "answer", "any", "by", "bye", "their"]
for word in words:
    trie.insertion(word)

trie.all_words()
