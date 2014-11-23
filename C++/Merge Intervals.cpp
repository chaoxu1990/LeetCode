/*

Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

 //Reuse the function of insert interval
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> result;
        for(int i = 0; i<intervals.size(); ++i)
        {
            result = insert(result, intervals[i]);
        }

        return result;
    }
private:
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        if(intervals.empty() || intervals[intervals.size() - 1].end < newInterval.start)
            intervals.push_back(newInterval);
        else if(intervals[0].start > newInterval.end)
            intervals.insert(intervals.begin(), newInterval);
        else
        {
            int first = 0, second = 0;
            for(int i = 0; i<intervals.size(); ++i)
            {
                if(intervals[i].end < newInterval.start)
                    first++;
                if(intervals[i].start <= newInterval.end)
                    second++;
            }

            int new_start = min(newInterval.start, intervals[first].start);
            int new_end = max(newInterval.end, intervals[second-1].end);
            Interval newInter(new_start, new_end);

            if(first != second)
            intervals.erase(intervals.begin() + first, intervals.begin() + second);

            intervals.insert(intervals.begin() + first, newInter);

        }

        return intervals;
    }
};
