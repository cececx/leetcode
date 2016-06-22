// Source : https://leetcode.com/problems/increasing-triplet-subsequence/
// Difficulty: Medium

/***********************************************************************
 *
 * Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.
 *
 **********************************************************************/



 
// Time O(n), Space O(1)
 
/* Correctness: 
 
   1. B will always be larger than A.
      >> Cuz if you want to update B with a number less than A, you'll update A instead.
      
   2. No matter A is updated before or after B, there's always a number before B that is smaller than B.
      >> Otherwise B will remain int_max because the following smaller number will be used to update A.

   3. Combine 1 and 2 we hv the result: If current number is larger than A and larger than B, it means: 
      (1) there exist an A < B where A is before B. 
      (2) B < C.
      

   4. Thus we keep updating the smaller A and B so that C is easier to be found.  <= Greedy

   5. I'm genius ヽ(●´ω｀●)/
*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int A(INT_MAX), B(INT_MAX);
        for (int n : nums) {
            if (n <= A) A = n;
            else if (n <= B) B = n;
            else return true;
        }
        return false;
    }
};