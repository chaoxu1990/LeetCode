/*

Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

*/

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> tmp_result;
        string result = "", old_result = "";
        for(string::iterator it = path.begin(); it != path.end();)
        {
            string tmp = "";
            if(*it == '/')
            {
                while(*(++it) == '/');
                for(;it != path.end(); ++it)
                {
                    if(*it=='/') {break;}
                    tmp += *it;
                }
            }
            if(tmp == ".") continue;
            else if(tmp == "..")
            {
                if(tmp_result.empty() != true)
                    tmp_result.pop();
            }
            else if(tmp.empty() == false)
                tmp_result.push(tmp);
        }
        if(tmp_result.empty() == true) return "/";
        while(tmp_result.empty() == false)
        {
            result = "/" + tmp_result.top() + result;
            tmp_result.pop();
        }

        return result;
    }
};

//for better solution see book 3.14
