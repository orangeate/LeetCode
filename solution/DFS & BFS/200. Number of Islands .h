#include "../global.h"
class Solution {
public:

    /* ---- dfs ----
    void dfs(vector<vector<char>>& grid, int x, int y)
    {
        grid[x][y] = '0';

        if(x+1 < grid.size() && grid[x+1][y] == '1')
            dfs(grid, x+1, y);
        if(y+1 < grid[0].size() && grid[x][y+1] == '1')
            dfs(grid, x, y+1);
        if(x-1 >= 0 && grid[x-1][y] == '1')
            dfs(grid, x-1, y);
        if(y-1 >= 0 && grid[x][y-1] == '1')
            dfs(grid, x, y-1);
    }

    int numIslands(vector<vector<char>>& grid)
    {
        int row = grid.size();
        if(row == 0)
            return 0;
        int col = grid[0].size();

        int ans = 0;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(grid[i][j] == '1')
                {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
    */
    /** ---- bfs ----**/
    int numIslands(vector<vector<char>>& grid)
    {
        int row = grid.size();
        if(row == 0)
            return 0;
        int col = grid[0].size();

        int ans = 0;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(grid[i][j] == '1')
                {
                    ans++;
                    queue<pair<int, int>> que;
                    que.push({i, j});

                    while(!que.empty())
                    {
                        int r = que.front().first;
                        int c = que.front().second;
                        que.pop();

                        if (r - 1 >= 0 && grid[r-1][c] == '1') {
                            que.push({r-1, c});
                            grid[r-1][c] = '0';
                        }
                        if (r + 1 < row && grid[r+1][c] == '1') {
                            que.push({r+1, c});
                            grid[r+1][c] = '0';
                        }
                        if (c - 1 >= 0 && grid[r][c-1] == '1') {
                            que.push({r, c-1});
                            grid[r][c-1] = '0';
                        }
                        if (c + 1 < col && grid[r][c+1] == '1') {
                            que.push({r, c+1});
                            grid[r][c+1] = '0';
                        }
                    }
                }
            }
        }
        return ans;
    }
};