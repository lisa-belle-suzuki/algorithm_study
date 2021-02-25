class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.tree = {}

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        cur = self.tree
        for i,c in enumerate(word):
            if c not in cur:
                cur[c] = {}
            if i == len(word) - 1:
                cur[c]['$'] = True
                return
            cur = cur[c]

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        cur = self.tree
        for i,c in enumerate(word):
            if c not in cur: return False
            if i == len(word)-1:
                if '$' in cur[c]: return True
            cur = cur[c]
        return False

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        cur = self.tree
        for c in prefix:
            if c not in cur: return False
            cur = cur[c]
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)