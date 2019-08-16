#include <string>
#include <unordered_map>
#include <vector>
#include <assert.h>

/**
 * Given two strings, write a method to decide if one is the permutation of the other.
 */
bool checkPermutation(std::string str1, std::string str2)
{
  if (str1.size() != str2.size())
    return false;

  std::unordered_map<char, int> chars;
  for (auto c: str1)
  {
    chars[c] += 1;
  }
  for (auto c: str2)
  {
    chars[c] -= 1;
    if (chars[c] < 0)
      return false;
  }
  return true;
}
//Time complexity: O(str1.size())
//Space complexity: O(1)


int main(int argc, char** argv)
{
  assert(checkPermutation("yes", "sye") == true);
  assert(checkPermutation("", "") == true);
  assert(checkPermutation("yys", "yes") == false);
  assert(checkPermutation("a", "b") == false);
  return 0;
}