// Given a valid (IPv4) IP `address`, return a defanged version of the IP address.
// A defanged IP address replaces every period "." with "[.]"

#include <iostream>
#include <string>

class Solution
{
public:
  std::string defangIPaddr(std::string address)
  {
    address.reserve(address.size() * 2);
    for (auto p = address.begin(); p != address.end(); ++p)
    {
      if (*p == '.')
      {
        p = address.insert(p, '[');
        p += 2;
        p = address.insert(p, ']');
      }
    }

    return address;
  }
};

int main()
{
  Solution s;
  std::cout << s.defangIPaddr("12.34.56.7.8") << "\n";
}