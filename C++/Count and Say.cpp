/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/


class Solution {
public:
      string countAndSay(int n) {
          string s("1");
          while (--n)
              s = getNext(s);
return s; }
      string getNext(const string &s) {
          stringstream ss;
          for (auto i = s.begin(); i != s.end(); ) {
              auto j = find_if(i, s.end(), bind1st(not_equal_to<char>(), *i));
              ss << distance(i, j) << *i;
              i = j;
          }
          return ss.str();
      }
};


/*
some Notes:

1). std:find_if(Inputerator first, Inputerator last, Unarypredicate pred)
{
    while(first != last)
    {
        if(pred(*first)) return first;
        ++first;
    }

    return last;
}

Find element in range Returns an iterator to the first element in the
range [first,last) for which pred returns true. If no such element is
found, the function returns last.

2). std::bind1st(const Operation& op, const T& x)
{
    return binder1st<Operation>(op, typename Operation::first_argument_type(x));
}

Return function object with first parameter bound.
This function constructs an unary function object from the binary function
object op by binding its first parameter to the fixed value x.

