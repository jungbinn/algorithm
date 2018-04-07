#include<algorithm>

using namespace std;

class ColorfulBoxesAndBalls
{
public:
	int getMaximum(int numRed, int numBlue, int onlyRed, int onlyBlue, int bothColors)
	{
		int score = (numRed * onlyRed) + (numBlue * onlyBlue);
		int less = min(numRed, numBlue);

		for (int i = 1; i <= less; i++)
		{
			int newScore = ((numRed - i) * onlyRed) + ((numBlue - i) * onlyBlue) + (2 * i * bothColors);
			score = max(score, newScore);
		}

		return score;
	}
};
