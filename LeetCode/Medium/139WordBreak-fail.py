class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        wordDict.sort()
        initial_to_words = {}
        for w in wordDict:
            initial = w[0]
            if initial in initial_to_words:
                initial_to_words[initial].append(w)
            else:
                initial_to_words[initial] = [w]

        def search_substr(tgt_str):
            substr_list = []
            initial = tgt_str[0]
            if initial not in initial_to_words:
                return []
            words = initial_to_words[initial]
            for w in words:
                if w == tgt_str[:len(w)]:
                    substr_list.append(w)
            return substr_list

        def solve(rest_str):
            if rest_str == "":
                return True
            substrs = search_substr(rest_str)
            if len(substrs) == 0:
                return False
            ok = False
            for sub in substrs:
                if solve(rest_str[len(sub):]):
                    return True

        if solve(s):
            return True
        else:
            return False
