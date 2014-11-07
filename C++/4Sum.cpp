/*

Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)

*/


class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > result;
        vector<int> tmp;

        if(num.size() < 4) return result;
        sort(num.begin(), num.end());

        for(int i = 0; i<num.size() - 3; ++i)
        {
            if(num[i] > target && num[i+1] > 0) break;
            if(i>0 && num[i] == num[i-1]) continue;
            for(int j = i+1; j<num.size()-2; ++j)
            {
                if(num[i] + num[j]> target && num[j+1] > 0) break;
                if(j>i+1 && num[j] == num[j-1]) continue;
                for(int k = j+1, l = num.size()-1; k<l;)
                {
                    if(num[i] + num[j] + num[k] > target && num[k+1] > 0) break;
                    if(k>j+1&& num[k] == num[k-1]) {k++; continue;}
                    if(l<num.size()-1 && num[l] == num[l+1]){l--; continue;}

                    if(num[i] + num[j] + num[k] + num[l]> target) l--;
                    else if(num[i] + num[j] + num[k] + num[l]< target) k++;
                    else
                    {
                        tmp.push_back(num[i]);
                        tmp.push_back(num[j]);
                        tmp.push_back(num[k]);
                        tmp.push_back(num[l]);
                        result.push_back(tmp);
                        tmp.clear();
                        l--;
                        k++;
                    }
                }
            }
        }
        return result;
    }
};

//Solution No.2: using hash

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > result;
        vector<int> tmp;
        if(num.size() < 4) return result;
        sort(num.begin(), num.end());

        map<int, vector<pair<int, int> > > cache;

        for(int i = 0; i + 1< num.size(); ++i)
        {
            for(int j = i + 1; j<num.size(); ++j)
            {
                cache[num[i]+num[j]].push_back(pair<int,int>(i,j));
            }
        }

        for(int i = 0; i + 3 < num.size(); ++i)
        {
            if(num[i] > target && num[i+1] > 0) break;
            if(i>0 && num[i] == num[i-1]) continue;
            for(int j = i + 1; j + 2<num.size(); ++j)
            {
                if(num[j] + num[i] > target && num[j+1] > 0) break;
                if(j>i+1 && num[j] == num[j-1]) continue;
                int key = target - num[i] - num[j];

                if(cache.find(key) == cache.end()) continue;
                vector<pair<int,int>> half;
                half = cache[key];

                for(int k = 0; k<half.size(); ++k)
                {
                    if(j>=half[k].first) continue;
                    tmp.push_back(num[i]);
                    tmp.push_back(num[j]);
                    tmp.push_back(num[half[k].first]);
                    tmp.push_back(num[half[k].second]);

                    vector<vector<int>>::iterator it = result.begin();
                    while(it!=result.end())
                    {
                        if(*it != tmp)
                            it++;
                        else
                            break;
                    }
                    if(it==result.end())
                        result.push_back(tmp);

                    tmp.clear();
                }
            }
        }

        return result;
    }
};
