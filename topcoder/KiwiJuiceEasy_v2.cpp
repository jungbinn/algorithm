#include <vector>
#include <algorithm>

using namespace std;

class KiwiJuiceEasy
{
public:
    vector<int> thePouring(vector<int> capacities, vector<int> bottles, vector<int> fromId, vector<int> toId)
    {
        for (int i = 0; i < fromId.size(); i++)
        {
            int fromIdx = fromId[i];
            int toIdx = toId[i];

            // To minimize if-else statements, use min function
            int transfer = min(bottles[fromIdx], capacities[toIdx]-bottles[toIdx]);

            bottles[fromIdx] -= transfer;
            bottles[toIdx] += transfer;
        }
        
        return bottles;
    }
};
