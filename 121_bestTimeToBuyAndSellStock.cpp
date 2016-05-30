// Sourse : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Difficulty : Easy

/***********************************************************************
 *
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * If you were only permitted to complete at most one transaction
 * (ie, buy one and sell one share of the stock),
 * design an algorithm to find the maximum profit.
 * 
 **********************************************************************/
 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 生活常识终身缺陷表示交易一次是什么鬼_(:3TZ)_
        // 啊 任意日期买一次卖一次_(:3TZ)_
        
        if (prices.empty()) return 0;
        int low = prices[0], profit = 0;
        for (int p : prices) {
            if (p < low) low = p; // buy in lowest day
            else if (p-low > profit) profit = p-low; // update highest profit
        }
        return profit;
    }
};