#include<vector>

using namespace std;

class InterestingDigits
{
public:
    vector<int> digits(int base)
    {
        vector<int> answer;

        for (int n = 2; n < base; n++)  // except 0 and 1
        {
            bool flag = true;

            for (int i = 0; i < base; i++)
            {
                for (int j = 0; j < base; j++)
                {
                    for (int k = 0; k < base; k++)
                    {
                        if ((i + j*base + k*base*base) % n == 0 && (i + j + k) % n != 0)
                        {
                            flag = false;
                            break;
                        }
                    }
                    if (!flag) break;
                }
                if (!flag) break;
            }

            if (flag)
                answer.push_back(n);
        }

        return answer;
    }
};


