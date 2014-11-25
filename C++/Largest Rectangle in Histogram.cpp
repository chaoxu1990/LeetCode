//Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack<int> s;
        int sum = 0;
        height.push_back(0);
        for(int i = 0; i<height.size();)
        {
            if(s.empty() || height[i] > height[s.top()]) s.push(i++);
            else
            {
                int tmp = s.top();
                s.pop();
                sum = max(sum, height[tmp] * (s.empty()?i:i-s.top()-1));
            }
        }
        return sum;
    }
};
