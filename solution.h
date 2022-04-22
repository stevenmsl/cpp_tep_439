
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>

using namespace std;
namespace sol439
{
    class Solution
    {
    private:
        string _parse(string &expr, int &i);

    public:
        string parse(string &expr);
    };
}
#endif