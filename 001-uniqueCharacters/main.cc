#include <string>
#include <unordered_set>
#include <vector>
#include <assert.h>

/**
 * Implement an algorithm to determine if a string has all unique characters
 */
bool hasUniqueCharacters(std::string str)
{
  if (str.size() > 256)
    return false;
  std::unordered_set<char> set(str.begin(), str.end()); //O(str.size())
  return set.size() == str.size();
}
//Time complexity: O(str.size())
//Space complexity: O(str.size())

/**
 * What if you cannot use additional data structures ? We can assume that the string
 * only uses lowercase letters
 */
bool hasUniqueCharacters2(std::string str)
{
  if (str.size() > 256)
    return false;
  int bits32 = 0;
  for (auto c: str)
  {
    char bitIndex = c - 'a';
    if ((bits32 & (1 << bitIndex)) > 0)
    {
      return false;
    }
    bits32 |= 1 << bitIndex;
  }
  return true;
}
//Time complexity: O(str.size())


int main(int argc, char** argv)
{
  std::vector<std::string> uniques{"", "yes", "no"};
  std::vector<std::string> notUniques{"aa", "non"};
  for (auto s: uniques)
  {
    assert(hasUniqueCharacters(s) == true);
    assert(hasUniqueCharacters2(s) == true);
  }
  for (auto s: notUniques)
  {
    assert(hasUniqueCharacters(s) == false);
    assert(hasUniqueCharacters2(s) == false);
  }
  return 0;
}