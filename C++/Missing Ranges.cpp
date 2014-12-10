/*

Given a sorted integer array where the range of elements are [lower, upper] inclusive, return its missing ranges.

For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].

*/

class Solution {
public:
    string build(int lower, int upper)
    {
        string tmp, right;
        tmp = to_string(lower);
        if(lower < upper)
        {
            tmp += "->";
            right = to_string(upper);
            tmp += right;
        }
        return tmp;
    }
    vector<string> findMissingRanges(int A[], int n, int lower, int upper) {
        vector<string> result;
        if(n==0)
        {
            result.push_back(build(lower, upper));
            return result;
        }

        if(A[0] > lower)
            result.push_back(build(lower, A[0] - 1));

        for(int i = 1; i < n; i++)
            if(A[i] - A[i-1] > 1)
                result.push_back(build(A[i-1] + 1, A[i] - 1));

        if(A[n-1] < upper)
            result.push_back(build(A[n-1] + 1, upper));

        return result;
    }
};
