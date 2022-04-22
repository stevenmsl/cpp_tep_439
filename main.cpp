#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol439;

/*
Input: "T?2:3"
Output: "2"
Explanation: If true, then result is 2; otherwise result is 3.
*/

tuple<string, string> testFixture1()
{

  return make_tuple("T?2:3", "2");
}

/*
Input: "F?1:T?4:5"
Output: "4"
Explanation: The conditional expressions group right-to-left. Using parenthesis,
it is read/evaluated as:

             "(F ? 1 : (T ? 4 : 5))"                   "(F ? 1 : (T ? 4 : 5))"
          -> "(F ? 1 : 4)"                 or       -> "(T ? 4 : 5)"
          -> "4"                                    -> "4"

*/

tuple<string, string> testFixture2()
{
  return make_tuple("F?1:T?4:5", "4");
}

/*
Input: "T?T?F:5:3"
Output: "F"
Explanation: The conditional expressions group right-to-left. Using parenthesis,
it is read/evaluated as:
             "(T ? (T ? F : 5) : 3)"                   "(T ? (T ? F : 5) : 3)"
          -> "(T ? F : 3)"                 or       -> "(T ? F : 5)"
          -> "F"                                    -> "F"
*/

tuple<string, string> testFixture3()
{
  return make_tuple("T?T?F:5:3", "F");
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 " << endl;
  cout << "Expect to see " << get<1>(f) << endl;
  Solution sol;
  cout << sol.parse(get<0>(f)) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Test 2 " << endl;
  cout << "Expect to see " << get<1>(f) << endl;
  Solution sol;
  cout << sol.parse(get<0>(f)) << endl;
}
void test3()
{
  auto f = testFixture3();
  cout << "Test 3 " << endl;
  cout << "Expect to see " << get<1>(f) << endl;
  Solution sol;
  cout << sol.parse(get<0>(f)) << endl;
}

main()
{
  test1();
  test2();
  test3();
  return 0;
}