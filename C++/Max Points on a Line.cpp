/*

Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

*/
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if(points.size() < 3) return points.size();
        int result = 0;
        for(int i = 0; i + 1<points.size(); ++i)
        {
            unordered_map<double, int> cache;
            int local_result = 1;
            int samePoint = 0;

            for(int j = i + 1; j<points.size(); ++j)
            {
                double slope = 0.0;

                if(points[i].x == points[j].x)
                {
                    slope = INT_MAX * 1.0;
                    if(points[i].y == points[j].y)
                    {
                            samePoint++;
                            continue;
                    }
                }
                else
                {
                    slope = 1.0 * (points[i].y - points[j].y) / (points[i].x - points[j].x);
                }
                if(cache.find(slope) == cache.end())
                {
                    cache[slope] = 2;
                }
                else cache[slope]++;
                if(local_result < cache[slope])
                    local_result = cache[slope];
            }
            if(result < local_result + samePoint) result = local_result + samePoint;
        }

        return result;
    }
};
