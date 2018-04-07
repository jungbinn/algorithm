#include<vector>

using namespace std;

class BadNeighbors
{
public:
	int maxDonations(vector<int> donations)
	{
		int sumtable[donations.size()];
		int sum1, sum2;

		/* Start from index 0 */
		sumtable[0] = donations[0];
		sumtable[1] = donations[1];
		sumtable[2] = donations[2] + donations[0];
		for (int i = 3; i < donations.size() - 1; i++)
			sumtable[i] = donations[i] + max(sumtable[i-2], sumtable[i-3]);
		sum1 = max(sumtable[donations.size()-2], sumtable[donations.size()-3]);

		/* Start from index 1 */
		sumtable[0] = 0;
		sumtable[2] = donations[2];
		sumtable[3] = donations[3] + donations[1];
		for (int i = 4; i < donations.size(); i++)
			sumtable[i] = donations[i] + max(sumtable[i-2], sumtable[i-3]);
		sum2 = max(sumtable[donations.size()-1], sumtable[donations.size()-2]);
		
		return max(sum1, sum2);
	}
};
