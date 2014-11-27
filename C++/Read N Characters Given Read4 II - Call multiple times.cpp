/*

The API: int read4(char *buf) reads 4 characters at a time from a file.

The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.

By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.

Note:
The read function may be called multiple times.

*/


// Forward declaration of the read4 API.
//
// 这道题我真的看不懂啊！！！谁能教教我这段代码究竟是在干什么？
int read4(char *buf);

class Solution {
private:
    char buff[4];
    int bufsize = 0;
    int offset = 0;
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    //Solution(): bufsize(0), offset(0){}

    int read(char *buf, int n) {
        int readBytes = 0;
        bool eof = false;

        while(eof == false && readBytes < n)
        {

            if(bufsize == 0)
            {
                bufsize = read4(buff);
                if(bufsize < 4) eof = true;
            }
            int bytes = min(bufsize, n-readBytes);
            memcpy(buf + readBytes, buff + offset, bytes);
            readBytes += bytes;
            bufsize -= bytes;
            offset = (offset + bytes)%4;
        }

        return readBytes;
    }
};
