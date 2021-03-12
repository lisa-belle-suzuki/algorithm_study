class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        # 普通のアルファベットと同じ並び順ならどういう文字列になるかを調べて，比較する

        alien_order = {}
        for i, o in enumerate(order):
            alien_order[o] = i

        def adapt_to_normal_style(word: str):
            new_word = ""
            for i in range(len(word)):
                c = word[i]
                new_c = chr(ord('a') + alien_order[c])
                new_word += new_c
            return new_word

        for i in range(len(words)-1):
            if adapt_to_normal_style(words[i]) > adapt_to_normal_style(words[i+1]):
                return False
        return True
