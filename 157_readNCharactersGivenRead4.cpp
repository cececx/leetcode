// Source : https://leetcode.com/problems/read-n-characters-given-read4/
// Difficulty: Easy

/***********************************************************************
 *
 * The API: int read4(char *buf) reads 4 characters at a time from a file.
 *
 * The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.
 *
 * By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.
 *
 **********************************************************************/

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int res = 0, cur = 4;
        while (cur == 4 && res < n) {
            cur = read4(buf + res);
            res += cur;
        }
        return min(res, n);
    }
};

// Notes: 指针加数字直接移位！！！！
// 最后返回的是有效长度！！！！