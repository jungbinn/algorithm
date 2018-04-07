#include<vector>
#include<string>
#include<algorithm>

// vector에 insert method 써서 한 vector 안에 집어넣으려고 했는데
// 내 의도대로 잘 안들어 가는 것 같다.
// 그냥 for문 돌리는 것밖에 답이 없나...

using namespace std;

class InterestingParty
{
public:
	int bestInvitation(vector<string> first, vector<string> second)
	{
		int num = 1;
		int max = 1;
		vector<string> topics;
		
		/* Put all topics in one vector and sort */
		topics.insert(topics.end(), first.begin(), first.end());
		topics.insert(topics.end(), second.begin(), second.end());
		sort(topics.begin(), topics.end());

		for (int i = 1; i < first.size()*2; i++)
		{
			num = 1;

			/* same topic */
			if (topics[i-1] == topics[i])
				num++;

			/* new topic */
			else
			{
				if (num > max)
					max = num;
			}
		}

		return max;
	}

	int main()
	{
		vector<string> first
		bestInvitation(first, second);
};
