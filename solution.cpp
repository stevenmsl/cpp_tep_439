#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <set>
#include <cstring>
using namespace sol439;
using namespace std;

/*takeaways
  - use F?1:T?4:5 as an example
  - scan the first char and get 'F'
  - the next char has to be '?' as it's a ternary expression
  - so we will skip it and look for ':' to find
    the first and second operands
  - we will get the first operand as 1 and stop there
  - the index is now pointing at T (expr[4])
  - so the question now becomes evaluating a simpler
    ternary expression: T?4:5
    - we do this recursively so in the end the
      second operand of the topmost ternary
      expression will come out as 4
  - so the entire expression becomes F ? 1: 4
  - so the answer is 4
*/

string Solution::_parse(string &expr, int &i)
{
  auto c = expr[i];
  /* tricky part
     - deal with case like 2:3
     - as the conditional expressions group right-to-left
       so the char prior to the ':' must be 'T', 'F", or
       '0'..'9' when you are scanning the chars from left
       to right
  */
  if (i + 1 == expr.size() || expr[i + 1] == ':')
  {
    /* it's fine that we exceed the length of expr as we will not explore
       any further
    */
    i += 2; /* skip ':' */
    return string(1, c);
  }

  i += 2; /* skip '?' */

  auto first = _parse(expr, i);
  auto second = _parse(expr, i);

  return c == 'T' ? first : second;
}

string Solution::parse(string &expr)
{
  auto i = 0;
  return _parse(expr, i);
}