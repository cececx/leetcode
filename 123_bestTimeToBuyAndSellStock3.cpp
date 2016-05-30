// Sourse : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// Difficulty : Hard

/***********************************************************************
 *
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. 
 * You may complete at most two transactions.
 * 
 **********************************************************************/
 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int size = prices.size(), low = prices[0], high = prices[size-1];
        vector<int> pre(size); // highest profit before i
        vector<int> aft(size); // highest profit after i
        
        for (int i=1; i<size; ++i) {
            low = min(low, prices[i]);
            pre[i] = max(pre[i-1], prices[i] - low);
        }
        
        for (int i=size-2; i>=0; --i) {
            high = max(high, prices[i]);
            aft[i] = max(aft[i+1], high - prices[i]);
        }
        
        int profit = 0;
        for (int i=1; i<size; ++i)
            profit = max(profit, pre[i]+aft[i]);
        
        return profit;
    }
};