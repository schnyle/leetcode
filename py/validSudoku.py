# Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
#   1. Each row must contain the digits 1-9 without repetition.
#   2. Each column must contain the digits 1-9 without repetition.
#   3. Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

from typing import List, Set


class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = [0] * 9
        cols = [0] * 9
        boxs = [0] * 9

        for i in range(0, 9):
            for j in range(0, 9):
                ele = board[i][j]
                if ele == '.':
                    continue

                bit = 1 << (int(ele) - 1)
                bIdx = (i // 3) * 3 + (j // 3)

                if rows[i] & bit or cols[j] & bit or boxs[bIdx] & bit:
                    return False

                rows[i] |= bit
                cols[j] |= bit
                boxs[bIdx] |= bit

        return True
