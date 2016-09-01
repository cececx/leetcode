// Sourse : https://leetcode.com/problems/ransom-note/
// Difficulty : Easy

/***********************************************************************
 *
 * ...
 *
 **********************************************************************/
 
// because ransomNote must be shorter, we count ransom note first
// for unicode, use unordered_map instead of int[128]. we use array here because it's faster

// Ignored edge case: ["", ""];
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.empty()) return true;
        if (ransomNote.size() > magazine.size()) return false;
        int count[128] = {0}, total = ransomNote.size();
        for(char c : ransomNote)
            count[c]++;
        for(char c : magazine) {
            if (count[c]) {
                count[c]--;
                total--;
            }
            if (!total) return true;
        }
        return false;
    }
};