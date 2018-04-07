#include <vector>

using namespace std;

class KiwiJuiceEasy
{
public:
	vector<int> thePouring(vector<int> capacities, vector<int> bottles, vector<int> fromId, vector<int> toId)
	{
		for (int i = 0; i < fromId.size(); i++)
		{
			int from = bottles[fromId[i]];
			int to = bottles[toId[i]];

			/* 완전히 옮겨지는 경우 */
			if (capacities[toId[i]] >= from + to)
			{
				bottles[fromId[i]] = 0;
				bottles[toId[i]] = from + to;
			}

			/* 다 못 옮길 경우 */
			else
			{
				bottles[fromId[i]] = from + to - capacities[toId[i]];
				bottles[toId[i]] = capacities[toId[i]];
			}
		}

		return bottles;
	}
};
