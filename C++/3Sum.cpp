/*

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)

*/


//My solution:
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
     sort(num.begin(), num.end());

     vector<vector<int> > result;
     vector<int> tmp;
     bool find = false;

     for(int i = 0; i<num.size(); ++i)
     {
         if(num[i] > 0) break;
         if(i>0 && num[i]==num[i-1]) continue;
         for(int j = i+1; j<num.size(); ++j)
         {
             if(num[i] + num[j] > 0) break;
             if(j>i+1 && num[j]==num[j-1]) continue;
             for(int k = j+1; k<num.size(); ++k)
             {
                 if(num[i] + num[j] + num[k] > 0) break;
                 if(k>j+1 && num[k]==num[k-1]) continue;
                 if(num[i] + num[j] + num[k] == 0)
                 {
                     tmp.push_back(num[i]);
                     tmp.push_back(num[j]);
                     tmp.push_back(num[k]);
                     for(int l = 0; l<result.size(); ++l)
                     {
                         if(result[l] == tmp)
                         {
                             find = true;
                             break;
                         }
                     }
                     if(find == false)
                        result.push_back(tmp);

                     tmp.clear();
                     find = false;
                 }
             }
         }
     }

     return result;
    }
};

//Solution No.2
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
     sort(num.begin(), num.end());

     vector<vector<int> > result;
     vector<int> tmp;
     if(num.size()<2) return result;
     for(int i = 0; i<num.size()-2; ++i)
     {
         if(num[i] > 0) break;
         if(i>0 && num[i]==num[i-1]) continue;
         for(int j = i+1, k = num.size()-1; j<k;)
         {
             if(num[i] + num[j] > 0) break;
             if(j>i+1 && num[j]==num[j-1])
             {
                 j++;
                 continue;
             }
             if(k<num.size()-1 && num[k] == num[k+1])
             {
                 k--;
                 continue;
             }
             if(num[i]+num[j]+num[k] > 0) k--;
             else if(num[i]+num[j]+num[k]<0) j++;
             else
             {
                 tmp.push_back(num[i]);
                 tmp.push_back(num[j]);
                 tmp.push_back(num[k]);
                 result.push_back(tmp);
                 tmp.clear();
                 j++;
                 k--;
             }
         }
     }
     return result;
    }
};
