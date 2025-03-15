# Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.

class Solution:
    def toLowerCase(self, s: str) -> str:
        ord_A = 65
        ord_Z = 90
        upper_case_range = range(ord_A, ord_Z + 1)
        upper_to_lower_diff = 32

        s_lower: str = ""
        for c in s:
            if ord(c) in upper_case_range:
                s_lower += chr(ord(c) + upper_to_lower_diff)
            else:
                s_lower += c

        return s_lower

if __name__ == "__main__":
    sol = Solution()
    res = sol.toLowerCase("GoDTiEr-AZ")
    print(res)