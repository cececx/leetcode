// Sourse : https://leetcode.com/problems/maximum-product-of-word-lengths/
// Difficulty : Medium

/***********************************************************************
 *
 * Given a string array words, find the maximum value of length(word[i]) * length(word[j]) 
 * where the two words do not share common letters. 
 *
 * You may assume that each word will contain only lower case letters. 
 * If no such two words exist, return 0.
 *
 **********************************************************************/

class Solution {
public:

    // 手写hash系列
    
    int maxProduct (vector<string>& words) {
        // preprocess
        int n = words.size();
        sort(words.begin(), words.end(), compare);
        
        // create dictionary
        vector<int> dict(n, 0);
        for (int i=0; i<n; ++i)
            dict[i] = intDictionary (words[i]);
            
        // check product
        int maxProd = 0;
        for (int i=n-1; i>0; --i) 
            for (int j=i-1; j>=0; --j)
                if (!(dict[i] & dict[j])) {
                    int prod = words[i].size() * words[j].size();
                    if (prod > maxProd) maxProd = prod;
                    break;
                }
        return maxProd;
    }
    
private:
    static bool compare(string s1, string s2) {
        return s1.length() < s2.length();
    }
    int intDictionary (string str) {
        int res = 0;
        for (char ch : str)
            res |= (1 << ch - 'a');
        return res;
    }
};