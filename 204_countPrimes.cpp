// Sourse : https://leetcode.com/problems/count-primes/
// Author : Cecilia Chen

// Difficulty : Easy

/***********************************************************************
 *
 * Count the number of prime numbers less than a non-negative number, n.
 *
 **********************************************************************/
 
class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) return 0;
        bool isPrime[n];
        memset(isPrime, true, sizeof(bool)*n);
        int count = n - 2;
        for (int i = 2; i*i < n; ++i) {
            if (!isPrime[i]) continue;
            for (int j = i*2; j < n; j += i) {
                if (isPrime[j]) {
                    isPrime[j] = false;
                    --count;
                }
            }
        }
        return count;
    }
};