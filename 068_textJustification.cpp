// Source : https://leetcode.com/problems/integer-to-english-words/
// Difficulty : Hard

/***********************************************************************
 *
 * Given an array of words and a length L, 
 * format the text such that each line has exactly L characters and is fully (left and right) justified.
 * 
 * You should pack your words in a greedy approach; that is, pack as many words as you can in each line. 
 * Pad extra spaces ' ' when necessary so that each line has exactly L characters.
 * 
 * Extra spaces between words should be distributed as evenly as possible. 
 * If the number of spaces on a line do not divide evenly between words, 
 * the empty slots on the left will be assigned more spaces than the slots on the right.
 *
 * For the last line of text, it should be left justified and no extra space is inserted between words.
 *
 * Input: 
 * words: ["This", "is", "an", "example", "of", "text", "justification."]
 * L: 16
 *
 * Output:
 * [
 *    "This    is    an",
 *    "example  of text",
 *    "justification.  "
 * ]
 *
 **********************************************************************/

// 0ms, Time O(n)
// 如今在下也是能一遍跑通hard的人了（作揖
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int begin = 0, size = words.size();
        vector<string> res;
        while (begin < size) {
            int end = begin + 1, count = words[begin].size();
            string line = words[begin];
            while (end < size && count + words[end].size() < maxWidth)
                count += words[end++].size() + 1;
            int a = 0, b = 0;
            if (end > begin + 1 && end < size) {         // if not the last line, set space between
                a = (maxWidth - count) / (end - begin - 1); 
                b = (maxWidth - count) % (end - begin - 1);
            }
            for (int i = begin + 1; i < end; ++i) {
                line += string(a + (b-->0) + 1, ' ');    // add space before word
                line += words[i];                        // add word
            }
            line += string(maxWidth - line.size(), ' '); // fill the blank after the whole line
            res.push_back(line);
            begin = end;
        }
        return res;
    }
};
