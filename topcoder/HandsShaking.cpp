#include<vector>

using namespace std;

class HandsShaking
{
public:
    long long countPerfect(int n)
    {
        int m = n / 2;
        vector<long long> count;
        count.push_back(1);  // set count[0] = 1

        for (int i = 1; i < m; i++)
        {
            long long s = 0;
            for (int j = 0; j < i; j++)
                s += count[j] * count[m-j];
            count.push_back(s);
        }

        return count.push_back(m);
    }
};
