# Given an integer `numRows`, return the first numRows of Pascal's Triangle.

from typing import List


class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res: List[List[int]] = []

        for m in range(0, numRows):
            row = [1] * (m + 1)

            # handle first two rows
            if (m == 0 or m == 1):
                res.append(row)
                continue

            # populate row
            last_row = res[m - 1]
            for i in range(1, m):
                row[i] = last_row[i - 1] + last_row[i]

            res.append(row)

        return res


s = Solution()
x = s.generate(5)
for row in x:
    print(row)
