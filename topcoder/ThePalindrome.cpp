#include<string>

using namespace std;

class ThePalindrome
{
public:
    int find(string s)
    {
        int len = s.size();

        /* 한 글자씩 대칭인지를 확인하고 아니면 뒤에 새 글자를 붙일 자리를 만듦 */
        while(1)
        {
            bool flag = true;
            
            for (int i = 0; i < s.size(); i++)
            {
                if ((len - i - 1) < s.size() && s[i] != s[len-i-1])
                {
                    flag = false;
                    break;
                }
            }

            if (flag) break;
            len++;
        }

        return len;
    }
};
