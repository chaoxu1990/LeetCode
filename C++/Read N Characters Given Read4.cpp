/*

The API: int read4(char *buf) reads 4 characters at a time from a file.

The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.

By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.

Note:
The read function will only be called once for each test case.

*/
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int tmp = 0, result = 0;
        bool end = true;
        while(n>0 && (tmp=read4(buf + result))>0)
        {
            if(n-4 >= 0 && tmp == 4)
            {
                n -= 4;
                result += 4;
            }
            else if(n - 4 >= 0 && tmp < 4)
            {
                result += tmp;
                break;
            }
            else if(n - 4 < 0 && tmp == 4)
            {
                result += n;
                break;
            }
            else if(n - 4 < 0 && tmp < 4)
            {
                result += min(n, tmp);
                break;
            }
        }

        return result;
    }
};

//Another better solution form book
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int readBytes = 0;
        bool eof = false;

        while(eof == false && readBytes < n)
        {
            int sz = read4(buf + readBytes);
            if(sz < 4) eof = true;
            int bytes = min(sz, n-readBytes);
            readBytes += bytes;
        }

        return readBytes;
    }
};
