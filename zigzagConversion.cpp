class Solution {
public:
	// pattern ¡ý
	// 0           6           12          18
	//   1       5   7       11  13      17  19
	//     2   4       8   10      14  16      20
	//       3           9           15

	string convert(string s, int numRows) {
		return solution2(s, numRows);
	}
	
	// 16ms solution
	string solution2(string s, int numRows) {
		if (s.size() <= numRows || numRows <= 1) return s;
		string z;
		int size = s.size(), len = numRows * 2 - 2;
		for (int i = 0; i<size; i += len) z += s[i];
		for (int row = 1; row<numRows - 1; row++) {
			int i = row, j = len - i;
			for (; j<size; i += len, j += len) {
				z += s[i];
				z += s[j];
			}
			if (i<size) z += s[i];
		}
		for (int i = numRows - 1; i<size; i += len) z += s[i];
		return z;
	}

	// 24ms straight forward solution
	string solution1(string s, int numRows) {
		if (numRows <= 1) return s;
		string result[numRows];
		int size = s.size();
		int row, len = numRows * 2 - 2;
		for (int i = 0; i<size; i++) {
			row = i % len;
			row = row < numRows ? row : len - row;
			result[row] += s[i];
		}
		string ret;
		for (int i = 0; i<numRows; i++) {
			ret += result[i];
		}
		return ret;
	}
};