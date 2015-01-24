class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(denominator == 1) return to_string(numerator);
        if(denominator == -1) return to_string(((long long)numerator*(-1)));

        long long numerator_tmp = abs((long long)numerator);
        long long denominator_tmp = abs((long long)denominator);
        map<int, int> table;
        string ret;
        if((numerator>0 && denominator<0) || (numerator<0 && denominator>0))ret = "-";
        long long ints = abs(numerator_tmp/denominator_tmp), fractional = abs(numerator_tmp%denominator_tmp);
        ret.append(to_string(ints));
        if(fractional != 0)
        {
            ret.append(".");
            int cnt = ret.size();
            int idx = cnt;
            while(table.find(fractional) == table.end())
            {
                ret.append(to_string(fractional*10/denominator_tmp));
                table[fractional] = idx++;
                fractional = fractional*10 % denominator_tmp;
                if(fractional == 0) break;
            }
            if(fractional != 0)
            {
                ret.insert(ret.begin() + table[fractional], '(');
                ret.append(")");
            }
        }

        return ret;
    }
};
