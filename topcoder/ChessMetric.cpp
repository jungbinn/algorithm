#include<vector>

using namespace std;

class ChessMetric
{
public:
	long long howMany(int size, vector<int> start, vector<int> end, int numMoves)
	{
		int dx[16] = {-1, 0, 1, -1, 1, -1, 0, 1, -2, -1, 1, 2, -2, -1, 1, 2};
		int dy[16] = {-1, -1, -1, 0, 0, 1, 1, 1, -1, -2, -2, -1, 1, 2, 2, 1};
		int x = start[0];
		int y = start[1];
		int endx = end[0];
		int endy = end[1];
		long long board[100][100][51] = {0};

		board[y][x][0] = 1;

		for (int n = 1; n <= numMoves; n++)
		{
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size; j++)
				{
					for (int k = 0; k < 16; k++)
					{
						x = i + dx[k];
						y = j + dy[k];

						if (x < 0 || y < 0 || x >= size || y >= size)
							continue;

						board[y][x][n] += board[j][i][n-1];
					}
				}
			}
		}

		return board[endy][endx][numMoves];
	}
};
