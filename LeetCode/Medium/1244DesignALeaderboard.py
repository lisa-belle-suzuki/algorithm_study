class Leaderboard:

    def __init__(self):
        self.player2score = defaultdict(int)

    def addScore(self, playerId: int, score: int) -> None:
        self.player2score[playerId] += score

    def top(self, K: int) -> int:
        scores = []
        for k in self.player2score.keys():
            scores.append(self.player2score[k])
        scores.sort(reverse=True)
        return sum(scores[:K])

    def reset(self, playerId: int) -> None:
        del self.player2score[playerId]


# Your Leaderboard object will be instantiated and called as such:
# obj = Leaderboard()
# obj.addScore(playerId,score)
# param_2 = obj.top(K)
# obj.reset(playerId)
