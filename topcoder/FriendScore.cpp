#include<vector>
#include<string>

using namespace std;

class FriendScore
{
public:
    int highestScore(vector<string> friends)
    {
        int highest = 0;
        int n = friends.size();

        for (int i = 0; i < n; i++)
        {
            int count = 0;
            vector<int> flag;

            /* initialize vector to 0 */
            for (int j = 0; j < n; j++)
                flag.push_back(0);
            flag[i] = 1;

            for (int j = 0; j < n; j++)
            {
                if (friends[i][j] == 'Y')
                {
                    count++;  // 직접친구
                    flag[j] = 1;

                    /* 친구의 친구 */
                    for (int k = 0; k < n; k++)
                    {
                        if (friends[k][j] == 'Y' && friends[i][k] == 'N' && flag[k] == 0)
                        {
                            count++;
                            flag[k] = 1;
                        }
                    }
                }
            }

            highest = max(highest, count);
        }

        return highest;
    }
};

