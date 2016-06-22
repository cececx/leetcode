// Source : https://leetcode.com/problems/peeking-iterator/
// Difficulty: Medium

/***********************************************************************
 *
 * Given an Iterator class interface with methods: next() and hasNext()
 *
 * Design and implement a PeekingIterator that support the peek() operation
 * -- it essentially peek() at the element that will be returned by the next call to next().
 *
 **********************************************************************/
 
 
 
// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.

class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator(); // Returns the next element in the iteration.
	int next(); // Returns true if the iteration has more elements.
	bool hasNext() const;
};



// Solutions:


/* 
    Solution 1
    Prestores the next element. Reduces unnecessary call of next().
*/

class PeekingIterator : public Iterator {
private:
    bool hasPeeked = false;
    int peekedElement;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {}
	int peek() {
        if (!hasPeeked) {
            hasPeeked = true;
            peekedElement = Iterator::next();
        }
        return peekedElement;
	}                                 
	int next() {                      
	    if (!hasPeeked) return Iterator::next();
	    hasPeeked = false;
	    return peekedElement;
	}
	bool hasNext() const {
	    return hasPeeked || Iterator::hasNext();
	}
};


/*
    Solution 2. without using extra variables
    
    (+) Neat solution.
        Although creates a new object, it uses only 4 bytes.
        Might be better than create two extra variables (5 bytes and more operations)

    (-) However if we modify the Iterator base class (i.e. add variables or parent class) the cost will increase.
    
    (-) Also if iterate operation is expansive (for this problem, it seems not) ....
        Hmmmm... but when peak() is frequently used, it'll be a waste, so I won't go for this solution anyway
    
    (-) 日常喷高票 你咬我呀wwwww
*/

class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {}
	int peek() {
        return Iterator(*this).next();
	}                                  
	int next() {                       
	    return Iterator::next();
	}
	bool hasNext() const {
	    return Iterator::hasNext();
	}
};


