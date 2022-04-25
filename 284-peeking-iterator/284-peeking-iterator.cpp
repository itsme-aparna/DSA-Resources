/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	   
	}
	
	int peek() {
        Iterator it= *this; //no function defines for peek so we create a function for it.
        return it.next();
	}
	
	int next() {
	    return Iterator ::next(); //calling next function
	}
	
	bool hasNext() const {
	   return Iterator:: hasNext(); //calling hasnext function
	}
};