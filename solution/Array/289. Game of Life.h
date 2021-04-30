#include "../global.h"
class Solution {
public:
    /* copy 一份
    void gameOfLife(vector<vector<int>>& board)
    {
        int neighbors[3] = {0, 1, -1};

        vector<vector<int>> board_bak(board);
        if(board.size() == 0)
            return;
        for(int row = 0; row < board.size(); row++)
        {
            for(int col = 0; col < board[0].size(); col++)
            {
                int num = 0;
                for(int i = 0; i < 3; i++)
                    for(int j = 0; j < 3; j++)
                    {
                        if(!(neighbors[i]==0 && neighbors[j]==0))
                        {
                            int r = (row + neighbors[i]);
                            int c = (col + neighbors[j]);
                            if ((r < board.size() && r >= 0) && (c < board[0].size() && c >= 0) && (board_bak[r][c] == 1))
                                num++;
                        }
                    }

                if(num < 2 || num > 3)
                    board[row][col] = 0;
                else if(num == 3)
                    board[row][col] = 1;
            }
        }
    }
    */
    /* ---- 增加状态 ----*/
    void gameOfLife(vector<vector<int>>& board)
    {
        int neighbors[3] = {0, 1, -1};

        if(board.size() == 0)
            return;
        for(int row = 0; row < board.size(); row++)
        {
            for(int col = 0; col < board[0].size(); col++)
            {
                int num = 0;
                for(int i = 0; i < 3; i++)
                    for(int j = 0; j < 3; j++)
                    {
                        if(!(neighbors[i]==0 && neighbors[j]==0))
                        {
                            int r = (row + neighbors[i]);
                            int c = (col + neighbors[j]);
                            if ((r < board.size() && r >= 0) && (c < board[0].size() && c >= 0) && (abs(board[r][c]) == 1))
                                num++;
                        }
                    }
                if((num < 2 || num > 3) && board[row][col] == 1)
                    board[row][col] = -1;
                if(num == 3 && board[row][col] == 0)
                    board[row][col] = 2;
            }
        }
        for(int row = 0; row < board.size(); row++)
            for(int col = 0; col < board[0].size(); col++)
                if(board[row][col] >= 1) board[row][col] = 1;
                else board[row][col] = 0;
    }
};
