// Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
//   1. Each row must contain the digits 1-9 without repetition.
//   2. Each column must contain the digits 1-9 without repetition.
//   3. Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

#include <vector>

class Solution
{
public:
  bool isValidSudoku(std::vector<std::vector<char>> &board)
  {
    std::vector<int> rows(9, 0);
    std::vector<int> cols(9, 0);
    std::vector<int> boxs(9, 0);

    for (int i = 0; i < 9; ++i)
    {
      for (int j = 0; j < 9; ++j)
      {
        const char ele = board[i][j];
        if (ele == '.')
        {
          continue;
        }

        const int bit = 1 << ((ele - '0') - 1);
        const int boxIdx = (i / 3) * 3 + (j / 3);

        if (rows[i] & bit || cols[j] & bit || boxs[boxIdx] & bit)
        {
          return false;
        }

        rows[i] |= bit;
        cols[j] |= bit;
        boxs[boxIdx] |= bit;
      }
    }

    return true;
  }
};