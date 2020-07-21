class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices)==0:
            return 0
        profit = [0]*len(prices)
        profit[0] = 0
        for i in range(1,len(prices)):
            j=0
            max_profit_at_j = 0
            while j<i:
                diff = prices[i] - prices[j]
                if diff < 0:
                    j+=1
                    continue
                if j - 2 > 0:
                    diff = profit[j-2] + diff
                if max_profit_at_j < diff:
                    max_profit_at_j = diff
                j+=1
            profit[i] = max_profit_at_j if max_profit_at_j > profit[i-1] else profit[i-1]
        return profit[len(prices)-1]
