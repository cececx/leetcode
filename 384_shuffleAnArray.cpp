// Sourse : https://leetcode.com/problems/shuffle-an-array/
// Difficulty : Medium

/***********************************************************************
 *
 * Shuffle a set of numbers without duplicates.
 *
 **********************************************************************/
 
class Solution {
private:
    vector<int> arr;
public:
    Solution(vector<int> nums) : arr(nums) {}
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return arr;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> shuffled = arr;
        for(int i = shuffled.size() - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            swap(shuffled[i], shuffled[j]);
        }
        return shuffled;
    }
};
