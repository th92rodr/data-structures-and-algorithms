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

    '''
    Key may not be there in trie. Delete operation should not modify trie.
    Key present as unique key (no part of key contains another key (prefix), nor the key itself is prefix of another key in trie). Delete all the nodes.
    Key is prefix key of another long key in trie. Unmark the leaf node.
    Key present in trie, having atleast one other key as prefix key. Delete nodes from end of key until first leaf node of longest prefix key.
    '''
    def delete(self, key):
        key.lower()
        current = self.root

        # variable to store the reverse path of this word in the trie
        path = []
        path.insert(0, current)

        # verify if the word exists in the trie and store the reverse path of the word
        for char in key:
            print('char:', char)
            # if the character is not found this word does not exists in the trie
            if char not in current.children:
                return False
            else:
                current = current.children[char]
                path.insert(0, current)

        print('last char', current.key, current.isEndOfWord)
        # delete path's first position which correspondes to the last character
        del path[0]

        if not current.children:
            # word is not prefix of any other word so it must be delete
            print('path', path)
            for node in path:
                print(node.key, end=' ')
            print()

            # while the current node does not belong to any other word delete it from it's parent children dictionary
            # not belonging to other word means not been a leaf and does not having children
            for node in path:
                del node.children[char]
                if node.isEndOfWord is True or node.children:
                    break
                else:
                    char = node.key

        else:
            # word is prefix of another word so it must not be delete
            # just unmark the node as a leaf (end of a word flag)
            current.isEndOfWord = False


    def print_trie(self):
        current = self.root
        if current is not None:
            print(current.key)
            print(current.children)
            current = self.root.children['a']
            print(current.key)
            print(current.children)
            current = current.children['b']
            print(current.key)
            print(current.children)
            current = current.children['c']
            print(current.key)
            print(current.children)
            print(current.isEndOfWord)

trie = Trie()
#trie.insertion('abc')
trie.insertion('abcd')
#trie.print_trie()
#print('abc:', trie.search('abc'))
#print('acd:', trie.search('acd'))
#print('acda:', trie.search('acda'))

trie.delete('abc')
print()
trie.print_trie()
