// Sourse : https://leetcode.com/problems/design-phone-directory/
// Difficulty : Hard

/***********************************************************************
 *
 * Design a Phone Directory which supports the following operations:
 *
 * Initialize with <maxNumber>
 *
 * 1. get: Provide a number which is not assigned to anyone.
 * 2. check: Check if a number is available or not.
 * 3. release: Recycle or release a number.
 *
 **********************************************************************/
 
// Init with the size of total numbers

// Valid[number] stores flags. Check O(1)
// Numbers<number> and an index. Index indicates the start of unused numbers.
// Get and Release only play around with <index> O(1)

class PhoneDirectory {
private:
    vector<int> numberPool;
    vector<bool> isValid;
    int index, count;
    
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int n) : numberPool(n), isValid(n, 1), index(0), count(n) {
        for (int i = 0; i < count; i++)
            numberPool[i] = i;
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        int n = -1;
        if (index < count) {
            n = numberPool[index++];
            isValid[n] = false;
        }
        return n;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return isValid[number];
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if (number < 0 || number >= count || isValid[number]) return;
        numberPool[--index] = number;
        isValid[number] = true;
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */