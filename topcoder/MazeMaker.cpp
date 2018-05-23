#include<vector>
#include<string>
#include<queue>

using namespace std;

class MazeMaker
{
public:
    int longestPath(vector<string> maze, int startRow, int startCol, vector<int> moveRow, vector<int> moveCol)
    {
        int m = maze.size();  // height of maze
        int n = maze[0].length();  // width of maze
        int moveCount[m][n];
        queue<int> qrow;
        queue<int> qcol;

        /* initialize */
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (maze[i][j] == 'X')
                    moveCount[i][j] = -1;
                else
                    moveCount[i][j] = 10000;
            }
        }
        int x = startRow;
        int y = startCol;
        moveCount[x][y] = 0;
        qrow.push(x);
        qcol.push(y);

        /* BFS */
        while (qrow.empty() == false)
        {
            x = qrow.front();
            y = qcol.front();
            qrow.pop();
            qcol.pop();

            for (int i = 0; i < moveRow.size(); i++)
            {
                int xx = x + moveRow[i];
                int yy = y + moveCol[i];
                if (0 <= xx && xx < m && 0 <= yy && yy < n)  // set the boundary
                {
                    if (maze[xx][yy] == '.' && moveCount[xx][yy] > moveCount[x][y] + 1)
                    {
                        qrow.push(xx);
                        qcol.push(yy);
                        moveCount[xx][yy] = moveCount[x][y] + 1;
                    }
                }
            }
        }

        /* Find the longest, or check if cannot escape the maze */
        int longest = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (moveCount[i][j] == 10000)
                    return -1;

                if (moveCount[i][j] != 10000 && moveCount[i][j] > longest)
                    longest = moveCount[i][j];
            }
        }
        return longest;
    }
};

