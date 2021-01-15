class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # min price from start
        # max price from end
        minPriceSoFar = []
        maxPriceSoFar = []
        i = 0
        curMin = 10001
        curMax = -1
        while i < len(prices):
            if prices[i] < curMin:
                curMin = prices[i]
            minPriceSoFar.append(curMin)

            if prices[-(1+i)] > curMax:
                curMax = prices[-(1+i)]
            maxPriceSoFar.append(curMax)

            i += 1

        # max profitを計算する
        maxPriceSoFar.reverse()
        i = 0
        maxProfit = -10001
        while i < (len(prices)-1):
            if maxPriceSoFar[i+1] - minPriceSoFar[i] > maxProfit:
                maxProfit = maxPriceSoFar[i+1] - minPriceSoFar[i]
            i += 1
        return max(0, maxProfit)
