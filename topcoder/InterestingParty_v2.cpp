#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

class InterestingParty
{
public:
	int bestInvitation(vector<string> first, vector<string> second)
	{
		map<string, int> dic;
		int maxCount = 0;
		int i;

		// initialize to zero
		for (i = 0; i < first.size(); i++)
		{
			dic[first[i]] = 0;
			dic[second[i]] = 0;
		}

		// count the interested people for each topics
		for (i = 0; i < first.size(); i++)
		{
			dic[first[i]]++;
			dic[second[i]]++;
		}

		// find the maximum count
		map<string, int>::iterator it;
		for (it = dic.begin(); it != dic.end(); it++)
			maxCount = max(maxCount, it->second);
		
		return maxCount;
	}
};
