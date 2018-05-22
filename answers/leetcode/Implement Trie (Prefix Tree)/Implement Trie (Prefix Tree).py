class TrieNode(object):
    def __init__(self):
        """
        Initialize your data structure here.
        """

        self.char_map = {}
        self.is_word = False

class Trie(object):

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        """
        Inserts a word into the trie.
        :type word: str
        :rtype: void
        """

        current = self.root
        for i in range(len(word)):
            if word[i] not in current.char_map:
                current.char_map[word[i]] = TrieNode()
            current = current.char_map[word[i]]
        current.is_word = True

    def search(self, word):
        """
        Returns if the word is in the trie.
        :type word: str
        :rtype: bool
        """

        current = self.root
        for i in range(len(word)):
            if word[i] not in current.char_map:
                return False
            current = current.char_map[word[i]]
        return current.is_word

    def startsWith(self, prefix):
        """
        Returns if there is any word in the trie
        that starts with the given prefix.
        :type prefix: str
        :rtype: bool
        """

        current = self.root
        for i in range(len(prefix)):
            if prefix[i] not in current.char_map:
                return False
            current = current.char_map[prefix[i]]
        return True

# Your Trie object will be instantiated and called as such:
# trie = Trie()
# trie.insert("somestring")
# trie.search("key")
