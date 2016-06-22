// Source : https://leetcode.com/problems/h-index/
// Difficulty : Medium

/***********************************************************************
 *
 * Given an array of citations (each citation is a non-negative integer) of a researcher, 
 * write a function to compute the researcher's h-index.
 * 
 * According to the definition of h-index on Wikipedia: 
 * "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."
 *
 **********************************************************************/

 
// Time O(nlogn), Space O(1). 会破坏原始数据
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        for (int i = n - 1; i>=0; --i)
            if (citations[i] >= n-i && citations[i-1] <= n-i)
                return n-i;
        return 0;
    }
};

// Time O(n), Space O(n)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        const int n = citations.size();
        int dp[n+1] = {0};
        for (int c : citations) {
            if (c >= n) ++dp[n];
            else ++dp[c];
        }
        int sum = 0;
        for (int i=n; i>=0; --i) {
            sum += dp[i];
            if (sum >= i)
                return i;
        }
        return 0;
    }
};
