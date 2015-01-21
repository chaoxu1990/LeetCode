/*
Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

For example,
add(1); add(3); add(5);
find(4) -> true
find(7) -> false
*/

class TwoSum {
public:
	void add(int number) {
	    table[number]++;
	}

	bool find(int value) {
	    for(auto it = table.begin(); it != table.end(); it++)
	    {
	        int num = value - it->first;
	        if((num == it->first && it->second >= 2) ||(num != it->first && table.find(num) != table.end()))
	            return true;
	        
	    }
	   
	    return false;
	}
	
private:
    unordered_map<int, int> table;
};
