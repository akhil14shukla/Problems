#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 2)
            {
                grid[i][j] += 1;
                queue<pair<int, int>> q;
                q.push({i, j});
                vector<vector<bool>> ch(10, vector<bool>(10, false));
                int cnt = 1;
                ch[i][j] = true;
                while (!q.empty())
                {
                    int i1 = q.front().first;
                    int j1 = q.front().second;
                    q.pop();
                    cnt--;
                    int flag = 1;
                    if (i1 + 1 < m && (grid[i1 + 1][j1] > 3 || grid[i1 + 1][j1] == 1) && !ch[i1 + 1][j1])
                    {
                        if (grid[i1 + 1][j1] == 1)
                        {
                            grid[i1 + 1][j1] = 100000000;
                        }
                        grid[i1 + 1][j1] = min(grid[i1 + 1][j1], grid[i1][j1] + 1);
                        q.push({i1 + 1, j1});
                        ch[i1 + 1][j1] = true;
                    }
                    if (i1 - 1 >= 0 && (grid[i1 - 1][j1] > 3 || grid[i1 - 1][j1] == 1) && !ch[i1 - 1][j1])
                    {
                        if (grid[i1 - 1][j1] == 1)
                        {
                            grid[i1 - 1][j1] = 100000000;
                        }
                        grid[i1 - 1][j1] = min(grid[i1 - 1][j1], grid[i1][j1] + 1);
                        q.push({i1 - 1, j1});
                        ch[i1 - 1][j1] = true;
                    }
                    if (j1 + 1 < n && (grid[i1][j1 + 1] > 3 || grid[i1][j1 + 1] == 1) && !ch[i1][j1 + 1])
                    {
                        if (grid[i1][j1 + 1] == 1)
                        {
                            grid[i1][j1 + 1] = 100000000;
                        }
                        grid[i1][j1 + 1] = min(grid[i1][j1 + 1], grid[i1][j1] + 1);
                        q.push({i1, j1 + 1});
                        ch[i1][j1 + 1] = true;
                    }
                    if (j1 - 1 < m && (grid[i1][j1 - 1] > 3 || grid[i1][j1 - 1] == 1) && !ch[i1][j1 - 1])
                    {
                        if (grid[i1][j1 - 1] == 1)
                        {
                            grid[i1][j1 - 1] = 100000000;
                        }
                        grid[i1][j1 - 1] = min(grid[i1][j1 - 1], grid[i1][j1] + 1);
                        q.push({i1, j1 - 1});
                        ch[i1][j1 - 1] = true;
                    }
                    if(!cnt){
                        cnt = q.size();
                    }
                }
            }
        }
    }
    int mx = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mx = max(mx, grid[i][j] - 3);
        }
    }
    return mx;
}

int main()
{
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << orangesRotting(grid) << endl;
    return 0;
}