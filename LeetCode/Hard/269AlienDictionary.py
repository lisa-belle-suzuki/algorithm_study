class Solution:
    def alienOrder(self, words: List[str]) -> str:
        # DAGのトポロジカルソート
        char_to_id = {}
        id_to_char = {}
        for w in words:
            for c in w:
                if c not in char_to_id:
                    i = len(char_to_id)
                    char_to_id[c] = i
                    id_to_char[i] = c

        # DAGを隣接リストで表現
        adja = [[] for _ in range(len(char_to_id))]
        indeg = [0] * len(char_to_id)
        for i in range(len(words)-1):
            cur_w = words[i]
            next_w = words[i+1]
            isDifferent = False
            for i in range(min(len(cur_w), len(next_w))):
                c1 = cur_w[i]
                c2 = next_w[i]
                if c1 != c2:
                    id1 = char_to_id[c1]
                    id2 = char_to_id[c2]
                    adja[id1].append(id2)
                    indeg[id2] += 1
                    isDifferent = True
                    break
            if not isDifferent and len(cur_w) > len(next_w):
                return ""

        # cycleがあったらダメ
        def isCyclicDFS(node):
            stack = []
            visited = []
            for a in adja[node]:
                stack.append(a)
            while stack:
                cur = stack.pop()
                if cur == node:
                    print("aaa", cur, id_to_char[cur])
                    return True
                if cur in visited:
                    continue
                visited.append(cur)
                for a in adja[cur]:
                    stack.append(a)
            return False

        for i in range(len(char_to_id)):
            if isCyclicDFS(i):
                return ""

        # indegが0のものから順にみていく
        visited = []
        # indegが0のものを探す
        zero_indeg = []
        for i in range(len(char_to_id)):
            if indeg[i] == 0:
                zero_indeg.append(i)

        while len(visited) < len(char_to_id):
            for node in zero_indeg:
                if node in visited:
                    continue
                # そこから，たどれる範囲でDFSで辿る
                stack = [node]
                while stack:
                    cur = stack.pop()
                    if cur in visited:
                        continue
                    visited.append(cur)
                    for a in adja[cur]:
                        indeg[a] -= 1
                        if indeg[a] == 0:
                            stack.append(a)

        return "".join([id_to_char[v] for v in visited])
