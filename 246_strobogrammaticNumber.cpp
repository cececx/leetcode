// Sourse : https://leetcode.com/problems/strobogrammatic-number/
// Difficulty : Easy

/***********************************************************************
 *
 * A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
 * 
 * Write a function to determine if a number is strobogrammatic. The number is represented as a string.
 * 
 * For example, the numbers "69", "88", and "818" are all strobogrammatic.
 *
 **********************************************************************/

 
class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> map({{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}});
        int left = 0, right = num.size() - 1;
        while (left <= right)
            if (map[num[left++]] != num[right--])
                return false;
        return true;
    }
};