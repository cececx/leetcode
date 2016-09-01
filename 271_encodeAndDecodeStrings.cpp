// Sourse: https://leetcode.com/problems/encode-and-decode-strings/
// Difficulty : Medium

/***********************************************************************
 *
 * Design an algorithm to encode a list of strings to a string. 
 * The encoded string is then sent over the network and is decoded back to the original list of strings.
 *
 **********************************************************************/

// encode: len + '@' + str

class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;
        for (string s : strs) {
            int len = s.size();
            res += to_string(len) + "@" + s;
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int start = 0, n = s.size();
        vector<string> res;
        while (start < n) {
            int a = s.find_first_of('@', start);
            int len = stoi(s.substr(start, a - start));
            res.push_back(s.substr(a + 1, len));
            start = a + 1 + len;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));