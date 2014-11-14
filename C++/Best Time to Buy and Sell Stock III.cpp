/*

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

*/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int size = prices.size();
        if(size<2) return 0;
        int minval = prices[0], maxval = prices[size-1];
        int maxprofit = 0;
        vector<int> leftprofit(size, 0);
        vector<int> rightprofit(size, 0);

        for(int i = 1; i<size; ++i)
        {
            minval = min(minval, prices[i]);
            leftprofit[i] = max(leftprofit[i-1], prices[i]-minval);
        }

        for(int i = size-2; i>=0; --i)
        {
            maxval = max(maxval, prices[i]);
            rightprofit[i] = max(rightprofit[i+1], maxval - prices[i]);
        }

        for(int i = 0; i < size; ++i)
        {
            maxprofit = max(maxprofit, leftprofit[i] + rightprofit[i]);
        }

        return maxprofit;
    }
};
