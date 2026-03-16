/**
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is
 * valid.
 * An input string is valid if:
 * 1. Open brackets must be closed by the same type of brackets.
 * 2. Open brackets must be closed in the correct order.
 * 3. Every close bracket has a corresponding open bracket of the same type.
 *
 * Example 1:
 * Input: s = "()"
 * Output: true
 *
 * Example 2:
 * Input: s = "()[]{}"
 * Output: true
 *
 * Example 3:
 * Input: s = "(]"
 * Output: false
 *
 * Example 4:
 * Input: s = "([])"
 * Output: true
 *
 * Example 5:
 * Input: s = "([)]"
 * Output: false
 *
 * Constraints:
 * 1 <= s.length <= 104
 * s consists of parentheses only '()[]{}'.
 */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isValid(char *s)
{
  int len = strlen(s);
  if (len % 2 != 0)
    return false;

  char stack[len / 2];
  int top = 0;

  while (*s != '\0')
  {
    switch (*s)
    {
    case '(':
      stack[top++] = ')';
      break;
    case '{':
      stack[top++] = '}';
      break;
    case '[':
      stack[top++] = ']';
      break;
    case ')':
    case '}':
    case ']':
      if (top < 1 || stack[top - 1] != *s)
        return false;
      --top;
      break;
    }

    ++s;
  }

  return top == 0;
}

int main()
{
  char *s = "()";
  printf("result: %s\n", isValid(s) ? "yes" : "no");
}
