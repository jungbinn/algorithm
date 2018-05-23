#include <vector>
#include <algorithm>

using namespace std;

class Cryptography
{
public:
    long long encrypt(vector<int> numbers)
    {
        /* increasing the minimum number is the best */
        sort(numbers.begin(), numbers.end());
        numbers[0]++;

        /* calculate product */
        long long product = 1;
        for (int i = 0; i < numbers.size(); i++)
            product *= numbers[i];

        return product;
    }
};
