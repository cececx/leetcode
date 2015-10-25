class Solution {
public:
	int reverse(int x) {
		// once upon a time there was a long long integer
		long long y = 0;
		while (x) {
			y = 10 * y + x % 10;
			x /= 10;
		}
		// and it lived happy ever after
		return (y < INT_MIN || y > INT_MAX) ? 0 : y;
	}
};