class Solution:
    def minCost(self, s: str, cost: List[int]) -> int:
        cost_list = []
        ans = 0
        for i, c in enumerate(s):
            # 前の文字と一緒だったら or 1文字目だったら
            if i == 0 or s[i] == s[i-1]:
                # costを加算
                cost_list.append(cost[i])
            # 前の文字と違ったら
            else:
                # 前の文字までのcostの和を，答えに足す
                if len(cost_list) > 1:

                    ans += sum(cost_list) - max(cost_list)
                # 今の文字のcostを計算
                cost_list = [cost[i]]

        # 最後に，最後の文字のcostを足し上げる
        if len(cost_list) > 1:
            ans += sum(cost_list) - max(cost_list)

        return ans
