// Sourse : https://leetcode.com/problems/bulb-switcher/
// Difficulty : Medium

/***********************************************************************
 *
 * There are n bulbs that are initially off. 
 * 1. You first turn on all the bulbs. 
 * 2. Then, you turn off every second bulb. 
 * 3. On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). 
 * 4. For the ith round, you toggle every i bulb. 
 * 5. For the nth round, you only toggle the last bulb. 
 * 
 * Find how many bulbs are on after n rounds.
 *
 **********************************************************************/

class Solution {
public:
    int bulbSwitch(int n) {
        // on: odd factors
        // off: even factors
        // odd factors -> square number
        
        int count = 0;
        for (int i=1; i*i<=n; ++i)
            ++ count;
        return count;
    }
};