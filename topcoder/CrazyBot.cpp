/* 전체 탐색 문제 */

using namespace std;

bool field[100][100] = {false};
double prob[4];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

class CrazyBot
{
public:
    double getProbability(int n, int east, int west, int south, int north)
    {
        prob[0] = east / 100.0;
        prob[1] = west / 100.0;
        prob[2] = south / 100.0;
        prob[3] = north / 100.0;

        return search(n, 50, 50);
    }

    double search(int count, int x, int y) 
    {
        if (field[x][y])  return 0;  // pruning(가지치기)
        if (count == 0)  return 1;  // terminate condition

        double p = 0.0;
        field[x][y] = true;

        /* DFS */
        for (int i = 0; i < 4; i++)
            p += prob[i] * search(count-1, x+dx[i], y+dy[i]);
        field[x][y] = false;

        return p;
    }
};
