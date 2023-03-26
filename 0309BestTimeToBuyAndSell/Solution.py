from typing import List

class Solution:
    def maxProfitEasy(self, prices: List[int]):
        if len(prices) == 1:
            return 0
        maxprofit = 0
        maxback = -100000
        minfront = 100000
        for idx in range(len(prices)):
            if prices[idx] < minfront:
                minfront = prices[idx]
                maxback = -100000
            elif prices[idx] > maxback:
                maxback = prices[idx]
            if maxprofit < maxback - minfront:
                maxprofit = maxback - minfront

        return maxprofit
            

    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) == 1:
            return 0

        mat = [[0] * len(prices) for i in range(len(prices))]
        maxval = [0] * len(prices)

        for i in range(len(prices)-1):
            for j in range(i+1, len(prices)):
                if i == 0 or i == 1:
                    mat[i][j] = prices[j] - prices[i]
                else:
                    mat[i][j] = maxval[i-2] + prices[j] - prices[i]
                if maxval[j] < mat[i][j]:
                    maxval[j] = mat[i][j]
                if  maxval[j] < maxval[j-1]:
                    maxval[j] = maxval[j-1]
        # for m in mat:
        #     print(m)
        # print(maxval)
        return max(map(max ,mat))
    
    def maxProfitFast(self, prices: List[int]):
        sold, held, reset = float('-inf'), float('-inf'), 0
        print('pre', 'sold', 'held', 'rst', 'price', sep='\t')
        for price in prices:
            # Alternative: the calculation is done in parallel.
            # Therefore no need to keep temporary variables
            #sold, held, reset = held + price, max(held, reset-price), max(reset, sold)

            pre_sold = sold
            sold = held + price
            held = max(held, reset - price)
            reset = max(reset, pre_sold)
            print(pre_sold, sold, held, reset, price, sep='\t')

        return max(sold, reset)

    # public int maxProfit(int[] prices){
    #     int len=prices.length;
    #     if(len==0)return 0;
    #     int[][] dp=new int[prices.length][3];
    #     dp[0][0]=dp[0][2]=0;
    #     dp[0][1]=-prices[0];
    #     int min_buy=dp[0][1];
    #     for(int i=1;i<len;i++){
    #         dp[i][0]=min_buy+prices[i];// sell
    #         dp[i][1]=dp[i-1][2]-prices[i];// buy
    #         dp[i][2]=Math.max(dp[i-1][2],dp[i-1][0]);
    #         min_buy=Math.max(min_buy, dp[i][1]);
    #     }
    #     return Math.max(dp[len-1][0],dp[len-1][2]);
    # }

if __name__ == '__main__':
    sol = Solution()
    testcases = [
        [2,1,4,5,2,9,7],
        [6,1,6,4,3,0,2],
        [2,1,2,0,1],
        [1,2,3,0,2],
        [5,5,4,9,3,8,5,5,1,6,8,3,4]
    ]
    for t in testcases:
        print(t)
        res = sol.maxProfitFast(t)
        print(res)
