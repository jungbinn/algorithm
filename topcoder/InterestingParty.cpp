#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class InterestingParty
{
public:
	int bestInvitation(vector<string> first, vector<string> second)
	{
		int maxTopic = 1;
		int count = 1;
		int i, j;
		int size = first.size();
		vector<string> topics;

		// put first and second into one matrix
		for (i = 0; i < size; i++)
		{
			topics.push_back(first[i]);
			topics.push_back(second[i]);
		}

		for (i = 0; i < size; i++)
		{
			count = 1;

			// count the number of people who has same interest in the topic
			for (j = i + 1; j < size * 2; j++)
			{
				if (topics[i] == topics[j])
					count++;
			}

			// compare with the current maximum value
			if (maxTopic < count)
				maxTopic = count;
		}

		return maxTopic;
	}
};
