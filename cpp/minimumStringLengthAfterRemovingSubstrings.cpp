// You are given a string `s` consisting only of uppercase English letters.
// You can apply some operations to this string where, in one operation, you can
// remove any occurence of one of the substrings "AB" or "CD" from `s`.
// Return the minimum possible length of the resulting string that you can
// obtain.

#include <iostream>
#include <string>

class Solution {
 public:
  int minLength(std::string s) {
    auto it = s.begin();
    while (it != s.end() - 1 && s.size() > 0) {
      int current = *it;
      int next = *(it + 1);
      if ((next == 'A' || next == 'C') && next - current == 1) {
        s.erase(it, it + 2);
        if (it != s.begin()) {
          --it;
        }
      } else {
        ++it;
      }
    }
    return s.size();
  }
};

int main() {
  // std::string s = "ABFCACDB";
  // std::string s = "CCCCDDDD";
  std::string s = "ACBBD";
  Solution sol;

  std::cout << sol.minLength(s) << "\n";
}