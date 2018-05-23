#include<vector>
#include<string>
#include<algorithm>
using namespace std;

long long salary[50] = {0};

class CorporationSalary
{
public:
    long long totalSalary(vector<string> relations)
    {
        for (int i = 0; i < relations.size(); i++)
        {
            if (salary[i] == 0)
                dfs(relations, i);
        }

        long long total = 0;
        for (int i = 0; i < relations.size(); i++)
            total += salary[i];
        return total;
    }

    long long dfs(vector<string> r, int i)
    {
        /* already searched */
        if (salary[i] != 0)
            return salary[i];

        /* 말단 직원 */
        if (count(r[i].begin(), r[i].end(), 'Y') == 0)
        {
            salary[i] = 1;
            return 1;
        }

        /* calculate salary */
        long long amount = 0;
        for (int j = 0; j < r.size(); j++)
        {
            if (r[i][j] == 'Y')
                amount += dfs(r, j);
        }
        salary[i] = amount;
        return amount;
    }
};
