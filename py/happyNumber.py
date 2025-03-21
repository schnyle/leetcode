# Write an algorithm to determine if a number n is happy.
# A happy number is a number defined by the following process:
#   - Starting with any positive integer, replace the number by the sum of the squares of its digits.
#   - Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
#   - Those numbers for which this process ends in 1 are happy.
# Return true if n is a happy number, and false if not.

class Solution:
    def isHappy(self, n: int) -> bool:
        history = set()
        history.add(n)

        while True:
            nSum = 0
            for digit in str(n):
                nSum += int(digit) * int(digit)
                print(digit, x)

            if nSum == 1:
                print("t")
                return True
            elif nSum in history:
                print("f")
                return False
            else:
                history.add(nSum)
                x = 0

        return False


s = Solution()
s.isHappy(19)
