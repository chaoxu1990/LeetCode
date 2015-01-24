class Solution {
public:
    int majorityElement(vector<int> &num) {
        if(num.size() == 1) return num[0];
        int cnt = 1, ret = num[0];

        for(int i = 1; i<num.size(); i++)
        {
            if(num[i] == ret){cnt++;}
            else if(cnt == 0){ret = num[i]; cnt = 1;}
            else    cnt--;
        }
        return ret;
    }
};
