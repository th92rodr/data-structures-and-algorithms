
class Node:
    def __init__(self, letter):
        self.letter = letter
        self.children = [None]*26
        # isEndOfWord is True if node represent the end of a word
        self.isEndOfWord = False
        self.meaning = ''

class Trie:
    def __init__(self):
        self.root = Node('')

    def insertion(self, word, meaning):
        word.lower()
        current = self.root

        for char in word:
            index = self._charToIndex(char)
            if current.children[index] is None:
                node = Node(char)
                current.children[index] = node
            current = current.children[index]
            node = current

        node.isEndOfWord = True
        node.meaning = meaning

    def search(self, word):
        word.lower()
        current = self.root

        for char in word:
            index = self._charToIndex(char)
            if current.children[index] is None:
                return False
            else:
                current = current.children[index]
        return current.meaning

    def _charToIndex(self, char):
        # private helper function
        # Converts key current character into index
        # use only 'a' through 'z' and lower case
        return ord(char)-ord('a')


trie = Trie()

trie.insertion("language", "the method of human communication")
trie.insertion("map", "a diagrammatic representation of an area")
trie.insertion("computer", "A computer is a machine that can be \
instructed to carry out sequences of arithmetic or \
logical operations automatically via computer programming")
trie.insertion("book", "a written or printed work \
consisting of pages glued or sewn together along one \
side and bound in covers.")
trie.insertion("science", "the intellectual and \
practical activity encompassing the systematic study \
of the structure and behaviour of the physical and \
natural world through observation and experiment.") 


print('Language:', trie.search('language'))
print('Map:', trie.search('map'))
print('Computer:', trie.search('computer'))
print('Book:', trie.search('book'))
print('Science:', trie.search('science'))

