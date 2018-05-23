#include<string>

using namespace std;

class NumberMagicEasy
{
public:
    int theNumber(string answer)
    {
        bool ans[4];

        for (int i = 0; i < 4; i++)
        {
            if (answer[i] == 'Y')
                ans[i] = true;
            else
                ans[i] = false;
        }

        for (int i = 1; i <= 16; i++)
        {
            if ((i <= 8) == ans[0])
            {
                if ((i % 8 > 0 && i % 8 <= 4) == ans[1])
                {
                    if ((i % 4 == 1 || i % 4 == 2) == ans[2])
                    {
                        if ((i % 2 == 1) == ans[3])
                            return i;
                    }
                }
            }
        }
        return 0;
    }
};
