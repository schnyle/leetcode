# Given an integer, convert it to a Roman numeral.

class Solution:
    def intToRoman(self, num: int) -> str:
        chars: dict = {
            1000: "M",
            900: "CM",
            500: "D",
            400: "CD",
            100: "C",
            90: "XC",
            50: "L",
            40: "XL",
            10: "X",
            9: "IX",
            5: "V",
            4: "IV",
            1: "I",
        }

        res: str = ""
        for value, symbol in chars.items():
            while value <= num:
                res += symbol
                num -= value

        return res


s = Solution()
for i in range(1, 20):
    print(f"{i}: {s.intToRoman(i)}")
# print(s.intToRoman(3749))
