// Sourse : https://leetcode.com/problems/pascals-triangle-ii/
// Difficulty : Easy

/***********************************************************************
 *
 * Given an index k, return the kth row of the Pascal's triangle.
 * 
 * For example, given k = 3, Return [1,3,3,1].
 * 
 **********************************************************************/
 
class Solution {
public:
    // the kth number in the nth row = C(n, k) = n! / (k! * (n-k)!)
    // C(n, k-1) = n! / ( (k-1)! * (n-k+1)! )
    // C(n, k) = C(n, k-1) * (n-k+1) / k
    
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1);
        ans[0] = ans[rowIndex] = 1;
        for (int i=1; i<= (rowIndex+1)/2; ++i)
            ans[i] = ans[rowIndex-i] = (unsigned long) ans[i-1] * (unsigned long) (rowIndex - i + 1) / i;
        return ans;
    }
};